int detail::sock_wrapper::send_abortable(const void *buf, std::size_t len, int flags)
{
	std::size_t count = 0;

	// We must allow aborting
	int handlepair[2];

	if (socketpair(PF_UNIX, SOCK_DGRAM, 0, handlepair))
		throw sock_error_ex("Cannot create abort socket pair");

	abort_send_socket = handlepair[0];

	fd_set writeset;
	fd_set readset;

	FD_ZERO(&writeset);
	FD_ZERO(&readset);
	FD_SET(sockhand, &writeset);
	FD_SET(handlepair[1], &readset);

	int maxhandle = std::max(sockhand, handlepair[1]) + 1;

	try {
		while (count < len) {
			if (select(maxhandle, &readset, &writeset, 0, 0) > 0) {
				if (FD_ISSET(sockhand, &writeset)) { /* Is TCP socket writable? */
					int in_count = ::send(sockhand, (char*)buf, len, flags);
					if (in_count<0)
						throw sock_error_ex("Cannot send to socket");
					count += in_count;
				}
				else if (FD_ISSET(handlepair[1], &readset)) { /* Is abort socket readable? */
					char ch;
					::recv(handlepair[1], &ch, sizeof(char), 0);
					// We ignore what we read. It must be an abort command
					break;
				}
			}
			else
				throw sock_error_ex("Cannot select input");
		}
	}
	catch (...) {
		close(handlepair[0]);
		close(handlepair[1]);
		abort_send_socket = -1;
		throw;
	}
	
	close(handlepair[0]);
	close(handlepair[1]);
	abort_send_socket = -1;

	return count;
}