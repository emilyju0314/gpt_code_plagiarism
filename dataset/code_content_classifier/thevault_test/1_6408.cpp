int
IPNetwork::drop_membership(Socket fd, in_addr& addr)
{

#if defined(IP_DROP_MEMBERSHIP)
	if (IN_CLASSD(ntohl(addr.s_addr))) {
		struct ip_mreq mr;

		mr.imr_multiaddr = addr;
		mr.imr_interface.s_addr = INADDR_ANY;
		if (::setsockopt(fd, IPPROTO_IP, IP_DROP_MEMBERSHIP, 
			       (char *)&mr, sizeof(mr)) < 0) {
			fprintf(stderr, "IPNetwork(%s): drop_membership: unable to drop membership for addr %s: %s\n",
				name(), inet_ntoa(addr), strerror(errno));
			return (-1);
		}
		NIDEBUG3("IPNetwork(%s): drop_membership for grp %s done\n",
			name(), inet_ntoa(addr));
		return (0);
	}
#else
	fprintf(stderr, "IPNetwork(%s): drop_membership: host does not support IP multicast\n",
		name());
#endif
	NIDEBUG3("IPNetwork(%s): drop_membership for grp %s failed\n",
		name(), inet_ntoa(addr));
	return (-1);
}