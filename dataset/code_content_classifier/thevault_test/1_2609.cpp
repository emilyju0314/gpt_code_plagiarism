int FocServer::callback_http(
	struct lws *wsi,
	enum lws_callback_reasons reason,
	void *user,
	void *in,
	size_t len)
{
	struct lws_context *context = lws_get_context(wsi);
	auto server = reinterpret_cast<FocServer*>(lws_context_user(context));
	int n, m;
	char *other_headers;
	struct per_session_data__http *pss = (struct per_session_data__http *)user;
	const char *mimetype;
	const char*	s_in = (const char*)in;

	switch (reason) {
	case LWS_CALLBACK_HTTP:
		{
			if (len < 1) {
				lws_return_http_status(wsi, HTTP_STATUS_BAD_REQUEST, NULL);
				return -1;
			}

			/* if a legal POST URL, let it continue and accept data */
			if (lws_hdr_total_length(wsi, WSI_TOKEN_POST_URI)) {
				return 0;
			}

			/* send a file the easy way */
			const char*	dotdotpos = strstr(s_in + 1, "..");
			std::string full_path;
			if (dotdotpos == nullptr) {
				full_path += server->_www_directory;
				if (len>0 && s_in[0] != '/') {
					full_path += '/';
				}
				full_path += std::string(s_in, s_in + len);
				if (full_path.size() > 0 && full_path[full_path.size() - 1] == '/') {
					full_path += "index.html";
				}
			} else {
				lwsl_err("Denying possible directory traversal request: %s\n", s_in);
				lws_return_http_status(wsi, HTTP_STATUS_NOT_FOUND, NULL);
				return 0;
			}

			/* refuse to serve files we don't understand */
			mimetype = get_mimetype(full_path);
			if (!mimetype) {
				lwsl_err("Unknown mimetype for %s\n", full_path.c_str());
				lws_return_http_status(wsi, HTTP_STATUS_UNSUPPORTED_MEDIA_TYPE, NULL);
				return -1;
			}

			other_headers = NULL;
			int other_headers_length = 0;

			const int r_serve = lws_serve_http_file(wsi, full_path.c_str(), mimetype, other_headers, other_headers_length);
			if (r_serve<0 || ((r_serve>0) && lws_http_transaction_completed(wsi))) {
				/* through completion or error, close the socket */
				return -1;
			}

			// Set the timeout depending on the file size.
			int content_timeout_sec = 30; // minimum 60 seconds.
			struct stat file_stats;
			if (stat(full_path.c_str(), &file_stats)==0) {
				content_timeout_sec += file_stats.st_size / (32 *  1024);
			}
			lws_set_timeout(wsi, PENDING_TIMEOUT_HTTP_CONTENT, content_timeout_sec);

			/*
			* notice that the sending of the file completes asynchronously,
			* we'll get a LWS_CALLBACK_HTTP_FILE_COMPLETION callback when
			* it's done
			*/
		}
		break;
	case LWS_CALLBACK_HTTP_BODY:
		lwsl_notice("LWS_CALLBACK_HTTP_BODY: len %d\n", (int)len);
		break;

	case LWS_CALLBACK_HTTP_BODY_COMPLETION:
		lwsl_notice("LWS_CALLBACK_HTTP_BODY_COMPLETION\n");
		/* the whole of the sent body arried, close the connection */
		lws_return_http_status(wsi, HTTP_STATUS_OK, NULL);

		goto try_to_reuse;

	case LWS_CALLBACK_HTTP_FILE_COMPLETION:
		//		lwsl_info("LWS_CALLBACK_HTTP_FILE_COMPLETION seen\n");
		/* kill the connection after we sent one file */
		goto try_to_reuse;

	case LWS_CALLBACK_HTTP_WRITEABLE:
		/*
		 * we can send more of whatever it is we were sending
		 */
		do {
			/* we'd like the send this much */
			n = sizeof(pss->buffer) - LWS_SEND_BUFFER_PRE_PADDING;

			/* but if the peer told us he wants less, we can adapt */
			m = lws_get_peer_write_allowance(wsi);

			/* -1 means not using a protocol that has this info */
			if (m == 0) {
				/* right now, peer can't handle anything */
				goto later;
			}

			if (m != -1 && m < n)
				/* he couldn't handle that much */
				n = m;

			n = read(pss->fd, pss->buffer + LWS_SEND_BUFFER_PRE_PADDING,
									n);
			/* problem reading, close conn */
			if (n < 0) {
				goto bail;
			}

			/* sent it all, close conn */
			if (n == 0) {
				goto flush_bail;
			}

			/*
			 * To support HTTP2, must take care about preamble space
			 *
			 * identification of when we send the last payload frame
			 * is handled by the library itself if you sent a
			 * content-length header
			 */
			m = lws_write(wsi, pss->buffer + LWS_SEND_BUFFER_PRE_PADDING,
					       n, LWS_WRITE_HTTP);
			if (m < 0) {
				/* write failed, close conn */
				goto bail;
			}

			// clear any timeouts.
			lws_set_timeout(wsi, PENDING_TIMEOUT_HTTP_CONTENT, 360);

			/*
			 * http2 won't do this
			 */
			if (m != n)
				/* partial write, adjust */
				if (lseek(pss->fd, m - n, SEEK_CUR) < 0) {
					goto bail;
				}

			if (m) {
				/* while still active, extend timeout */
				lws_set_timeout(wsi, PENDING_TIMEOUT_HTTP_CONTENT, 5);
			}

			/* if we have indigestion, let him clear it before eating more */
			if (lws_partial_buffered(wsi))
				break;

		} while (!lws_send_pipe_choked(wsi));

later:
		lws_callback_on_writable(wsi);
		break;
flush_bail:
		/* true if still partial pending */
		if (lws_partial_buffered(wsi)) {
			lws_callback_on_writable(wsi);
			break;
		}
		close(pss->fd);
		goto try_to_reuse;

bail:
		close(pss->fd);
		return -1;

	default:
		// Default to returning 0 when the message was not handled.
		return 0;
	}

	return 0;

try_to_reuse:
	if (lws_http_transaction_completed(wsi)) {
		return -1;
	}
	return 0;

}