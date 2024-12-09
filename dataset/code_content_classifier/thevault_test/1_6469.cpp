int
FullTcpAgent::reass(Packet* pkt)
{  
        hdr_tcp *tcph =  hdr_tcp::access(pkt);
        hdr_cmn *th = hdr_cmn::access(pkt);
   
        int start = tcph->seqno();
        int end = start + th->size() - tcph->hlen();
        int tiflags = tcph->flags();
	int fillshole = (start == rcv_nxt_);
	int flags;
   
	// end contains the seq of the last byte of
	// in the packet plus one

	if (start == end && (tiflags & TH_FIN) == 0) {
		fprintf(stderr, "%f: FullTcpAgent(%s)::reass() -- bad condition - adding non-FIN zero-len seg\n",
			now(), name());
		abort();
	}

	flags = rq_.add(start, end, tiflags, 0);

	//present:
	//
	// If we've never received a SYN (unlikely)
	// or this is an out of order addition, no reason to coalesce
	//

	if (TCPS_HAVERCVDSYN(state_) == 0 || !fillshole) {
	 	return (0x00);
	}
	//
	// If we get some data in SYN_RECVD, no need to present to user yet
	//
	if (state_ == TCPS_SYN_RECEIVED && (end > start))
		return (0x00);

	// clear out data that has been passed, up to rcv_nxt_,
	// collects flags

	flags |= rq_.cleartonxt();

        return (flags);
}