void
UDPIPNetwork::add_membership(Socket sock, in_addr& addr, u_int16_t port)
{
	int failure = 0;
	sockaddr_in sin;
	if (bindsock(sock, addr, port, sin) < 0)
		failure = 1;
	if (failure) {
		in_addr addr2 = addr;
		addr2.s_addr = INADDR_ANY;
		if (bindsock(sock, addr2, port, sin) < 0)
			failure = 1;
		else
			failure = 0;
	}

	if (IPNetwork::add_membership(sock, addr) < 0)
		failure = 1;

	if (failure) {
		fprintf(stderr,
		"UDPIPNetwork(%s): add_membership: failed bind on mcast addr %s and INADDR_ANY\n",
			name(), inet_ntoa(addr));
	}
}