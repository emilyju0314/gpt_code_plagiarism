void
ArpAgent::dispatch(int)
{
	double ts;
	sockaddr sa;
	int cc = net_->recv(rcv_buf_, base_size_, sa, ts);
	if (cc < int(base_size_ - sizeof(ether_header))) {
		if (cc == 0)
			return;
                fprintf(stderr,
                    "ArpAgent(%s): recv small pkt (%d) [base sz:%d]: %s\n",
                    name(), cc, base_size_, strerror(errno));
		return;
	}
	ether_arp* ea = (ether_arp*) rcv_buf_;
	int op = ntohs(ea->ea_hdr.ar_op);


	switch (op) {
	case ARPOP_REPLY:
		doreply(ea);
		break;
	case ARPOP_REQUEST:
		doreq(ea);
		break;
	default:
		fprintf(stderr,
		    "ArpAgent(%s): cannot interpret ARP op %d\n",
		    name(), op);
		return;
	}
	return;
}