icmp*
PingResponder::validate(int sz, ip* iph)
{
	if (sz < 20) {
		fprintf(stderr, "%f: PingResponder(%s): sim pkt too small for base IP header(%d)\n",
			Scheduler::instance().clock(), name(), sz);
		return (NULL);
	}

	int ipver = (*((char*)iph) & 0xf0) >> 4;
	if (ipver != 4) {
		fprintf(stderr, "%f: PingResponder(%s): IP bad ver (%d)\n",
			Scheduler::instance().clock(), name(), ipver);
		return (NULL);
	}

	int iplen = ntohs(iph->ip_len);
	int iphlen = (*((char*)iph) & 0x0f) << 2;
	if (iplen < (iphlen + 8)) {
		fprintf(stderr, "%f: PingResponder(%s): IP dgram not long enough (len: %d)\n",
			Scheduler::instance().clock(), name(), iplen);
		return (NULL);
	}

	if (sz < iplen) {
		fprintf(stderr, "%f: PingResponder(%s): IP dgram not long enough (len: %d)\n",
			Scheduler::instance().clock(), name(), iplen);
		return (NULL);
	}

	if (iphlen != 20) {
		fprintf(stderr, "%f: PingResponder(%s): IP bad hlen (%d)\n",
			Scheduler::instance().clock(), name(), iphlen);
		return (NULL);
	}

	if (Internet::in_cksum((u_short*) iph, iphlen)) {
		fprintf(stderr, "%f: PingResponder(%s): IP bad cksum\n",
			Scheduler::instance().clock(), name());
		return (NULL);
	}

	if (iph->ip_p != IPPROTO_ICMP) {
		fprintf(stderr, "%f: PingResponder(%s): not ICMP (proto: %d)\n",
			Scheduler::instance().clock(), name(), iph->ip_p);
		return (NULL);
	}


	if (iph->ip_off != 0) {
		fprintf(stderr, "%f: PingResponder(%s): fragment! (off: 0x%x)\n",
			Scheduler::instance().clock(), name(), ntohs(iph->ip_off));
		return (NULL);
	}

	if (iph->ip_src.s_addr == 0xffffffff || iph->ip_src.s_addr == 0) {
		fprintf(stderr, "%f: PingResponder(%s): bad src addr (%s)\n",
			Scheduler::instance().clock(), name(),
			inet_ntoa(iph->ip_src));
		return (NULL);
	}

	if (IN_MULTICAST(ntohl(iph->ip_src.s_addr))) {
		fprintf(stderr, "%f: PingResponder(%s): mcast src addr (%s)\n",
			Scheduler::instance().clock(), name(),
			inet_ntoa(iph->ip_src));
		return (NULL);
	}
	icmp* icp = (icmp*) (iph + 1);
	if (Internet::in_cksum((u_short*) icp, iplen - iphlen) != 0) {
		fprintf(stderr,
			"%f: PingResponder(%s): bad ICMP cksum\n",
			Scheduler::instance().clock(), name());
		return (NULL);
	}
	if (icp->icmp_type != ICMP_ECHO) {
		fprintf(stderr, "%f: PingResponder(%s): not echo request (%d)\n",
			Scheduler::instance().clock(), name(),
			icp->icmp_type);
		return (NULL);
	}

	if (icp->icmp_code != 0) {
		fprintf(stderr, "%f: PingResponder(%s): bad code (%d)\n",
			Scheduler::instance().clock(), name(),
			icp->icmp_code);
		return (NULL);
	}
	return (icp);
}