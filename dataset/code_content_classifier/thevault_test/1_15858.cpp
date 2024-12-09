int detail::sock_wrapper::recv_abortable(void *buf, std::size_t len, int flags)
{
	unsigned long count;

	if (ioctl(sockhand, FIONREAD, &count) < 0)
		throw sock_error_ex("Cannot get socket data count");

	if (count>0)
		// There is already data available - no need to allow aborting
		return ::recv(sockhand, (char*)buf, len, flags);


	// We must allow aborting
	int handlepair[2];

	if (socketpair(PF_UNIX, SOCK_DGRAM, 0, handlepair))
		throw sock_error_ex("Cannot create abort socket pair");

	abort_recv_socket = handlepair[0];

	fd_set readset;

	FD_ZERO(&readset);
	FD_SET(sockhand, &readset);
	FD_SET(handlepair[1], &readset);

	int maxhandle = std::max(sockhand, handlepair[1]) + 1;

	int retval=0;

	try {
		if (select(maxhandle, &readset, 0, 0, 0) > 0) {
			if (FD_ISSET(sockhand, &readset))	/* Is TCP socket readable? */
				retval = ::recv(sockhand, (char*)buf, len, flags);
			else if (FD_ISSET(handlepair[1], &readset))	{ /* Is abort socket readable? */
				char ch;
				::recv(handlepair[1], &ch, sizeof(char), 0);
				// We ignore what we read. It must be an abort command
			}
		}
		else
			throw sock_error_ex("Cannot select input");
	}
	catch (...) {
		close(handlepair[0]);
		close(handlepair[1]);
		abort_recv_socket = -1;
		throw;
	}
		
	close(handlepair[0]);
	close(handlepair[1]);
	abort_recv_socket = -1;

	return retval;
}