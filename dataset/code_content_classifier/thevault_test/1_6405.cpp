int
IPNetwork::open(int mode)
{
	// obtain a raw socket we can use to send ip datagrams
	Socket fd = socket(AF_INET, SOCK_RAW, IPPROTO_RAW);
	if (fd < 0) {
		perror("socket(RAW)");
		if (::getuid() != 0 && ::geteuid() != 0) {
			fprintf(stderr,
	  "IPNetwork(%s): open: use of the Network/IP object requires super-user privs\n",
			name());
		}

		return (-1);
	}

	// turn on HDRINCL option (we will be writing IP header)
	// in FreeBSD 2.2.5 (and possibly others), the IP id field
	// is set by the kernel routine rip_output()
	// only if it is non-zero, so we should be ok.
	int one = 1;
	if (::setsockopt(fd, IPPROTO_IP, IP_HDRINCL, &one, sizeof(one)) < 0) {
		fprintf(stderr,
	"IPNetwork(%s): open: unable to turn on IP_HDRINCL: %s\n",
			name(), strerror(errno));
		return (-1);
	}
#ifndef __linux__
	// sort of curious, but do a connect() even though we have
	// HDRINCL on.  Otherwise, we get ENOTCONN when doing a send()
	sockaddr_in sin;
	in_addr ia = { INADDR_ANY };
	if (connectsock(fd, ia, 0, sin) < 0) {
		fprintf(stderr,
	"IPNetwork(%s): open: unable to connect : %s\n",
			name(), strerror(errno));
	}
#endif
	rsock_ = ssock_ = fd;
	mode_ = mode;
	NIDEBUG5("IPNetwork(%s): opened with mode %d, rsock_:%d, ssock_:%d\n",
		name(), mode_, rsock_, ssock_);
	return 0;
}