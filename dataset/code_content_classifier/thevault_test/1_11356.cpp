int CURLReadStreamBase::FillBuffer(size_t nwant) {
  int nrun = 0;
  while (buffer_.length() < nwant) {
    // wait for the event of read ready
    fd_set fdread;
    fd_set fdwrite;
    fd_set fdexcep;
    FD_ZERO(&fdread);
    FD_ZERO(&fdwrite);
    FD_ZERO(&fdexcep);
    int maxfd = -1;
    // Curl default timeout as in: https://curl.haxx.se/libcurl/c/curl_multi_timeout.html
    timeval timeout;
    long curl_timeo = 0;
    curl_multi_timeout(mcurl_, &curl_timeo);
    if (curl_timeo < 0) curl_timeo = 980;
    timeout.tv_sec = curl_timeo / 1000;
    timeout.tv_usec = (curl_timeo % 1000) * 1000;
    ASSERT_TRUE(curl_multi_fdset(mcurl_, &fdread, &fdwrite, &fdexcep, &maxfd) == CURLM_OK);
    int rc;
    if (maxfd == -1) {
#ifdef _WIN32
      Sleep(100);
      rc = 0;
#else
      struct timeval wait = { 0, 100 * 1000 };
      rc = select(0, NULL, NULL, NULL, &wait);
#endif
    } else {
      rc = select(maxfd + 1, &fdread, &fdwrite, &fdexcep, &timeout);
    }
    if (rc != -1) {
      CURLMcode ret = curl_multi_perform(mcurl_, &nrun);
      if (ret ==  CURLM_CALL_MULTI_PERFORM) continue;
      ASSERT_TRUE(ret == CURLM_OK);
      if (nrun == 0) break;
    }
  }
  // loop through all the subtasks in curl_multi_perform and look for errors
  struct CURLMsg *m;
  do {
    int msgq = 0;
    m = curl_multi_info_read(mcurl_, &msgq);
    if(m && (m->msg == CURLMSG_DONE)) {
      if (m->data.result != CURLE_OK) {
        log_and_throw_io_failure(curl_easy_strerror(m->data.result));
      }
    }
  } while(m);

  return nrun;
}