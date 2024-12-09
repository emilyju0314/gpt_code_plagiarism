void HDLC::handleREJ(Packet *rejp)
{
	// set seqno_ = seqno in REJ
	// and start sending
	struct S_frame *sf = (struct S_frame *)&(HDR_HDLC(rejp)->hdlc_fc_);
	int seqno = sf->recv_seqno;
	int last_hop = HDR_CMN(rejp)->last_hop_;
	ARQstate *a = checkState(last_hop);
	
	if (a == 0 || a->SABME_req_ != 2) {
		printf("handleREJ: No state/connection found for %d\n", last_hop);
		return;
	}

	a->t_seqno_ = seqno;
	sendMuch(a);
	
	Packet::free(rejp);
}