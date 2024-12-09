void HDLC::handleSREJ(Packet *rejp)
{
	
	struct S_frame *sf = (struct S_frame *)&(HDR_HDLC(rejp)->hdlc_fc_);
	int seqno = sf->recv_seqno;
	int last_hop = HDR_CMN(rejp)->last_hop_;
	ARQstate *a = checkState(last_hop);
	
	if (a == 0 || a->SABME_req_ != 2) {
		printf("handleSREJ: No state/connection found for %d\n", last_hop);
		return;
	}

	// resend only the pkt that was requested
	Packet *p = getPkt(a->sendBuf_, seqno);
	Packet *dp = p->copy();
	
	output(dp, a, seqno);
	
	Packet::free(rejp);
	
}