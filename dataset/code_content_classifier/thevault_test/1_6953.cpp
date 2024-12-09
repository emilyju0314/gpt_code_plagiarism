void DelayBoxQueue::dumplist()
{
	register pktinfo* p = head_;
	Packet *pkt;
	hdr_tcp *tcph;
	hdr_cmn *ch;
	hdr_ip *iph;
	char str[50] = "";

	if (head_ == NULL) {
		fprintf(stderr, "    head_ is NULL\n");
		return;
	}

	while (p != NULL) {
		pkt = p->pkt_;
		tcph = hdr_tcp::access(pkt);
		ch = hdr_cmn::access(pkt);
		iph = hdr_ip::access(pkt);
		packet_string (str, tcph, iph, ch->size());
		fprintf (stderr, "\t%s at %f\n", str, p->delta_);
		p = p->next_;
	}
}