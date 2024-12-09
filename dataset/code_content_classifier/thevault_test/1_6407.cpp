int
IPNetwork::add_membership(Socket fd, in_addr& addr)
{

#if defined(IP_ADD_MEMBERSHIP)
	if (IN_CLASSD(ntohl(addr.s_addr))) {
#ifdef notdef
		/*
		 * Try to bind the multicast address as the socket
		 * dest address.  On many systems this won't work
		 * so fall back to a destination of INADDR_ANY if
		 * the first bind fails.
		 */
		sockaddr_in sin;
		memset(&sin, 0, sizeof(sin));
		sin.sin_family = AF_INET;
		sin.sin_addr = addr;
		if (::bind(fd, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
			sin.sin_addr.s_addr = INADDR_ANY;
			if (::bind(fd, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
				fprintf(stderr,
	"IPNetwork(%s): add_membership: unable to bind to addr %s: %s\n",
					name(), inet_ntoa(sin.sin_addr),
					strerror(errno));
				return (-1);
			}
		}
#endif
		/* 
		 * XXX This is bogus multicast setup that really
		 * shouldn't have to be done (group membership should be
		 * implicit in the IP class D address, route should contain
		 * ttl & no loopback flag, etc.).  Steve Deering has promised
		 * to fix this for the 4.4bsd release.  We're all waiting
		 * with bated breath.
		 */
		struct ip_mreq mr;

		mr.imr_multiaddr = addr;
		mr.imr_interface.s_addr = INADDR_ANY;
		if (::setsockopt(fd, IPPROTO_IP, IP_ADD_MEMBERSHIP, 
			       (char *)&mr, sizeof(mr)) < 0) {
			fprintf(stderr, "IPNetwork(%s): add_membership: unable to add membership for addr %s: %s\n",
				name(), inet_ntoa(addr), strerror(errno));
			return (-1);
		}
		NIDEBUG3("IPNetwork(%s): add_membership for grp %s done\n",
			name(), inet_ntoa(addr));
		return (0);
	}
#else
	fprintf(stderr, "IPNetwork(%s): add_membership: host does not support IP multicast\n",
		name());
#endif
	NIDEBUG3("IPNetwork(%s): add_membership for grp %s failed\n",
		name(), inet_ntoa(addr));
	return (-1);
}