void HDLC::handleRR(Packet *p)
{
	// recvd an ack for a pkt
	// remove data pkt from outgoing buffer, if applicable
	struct S_frame *sf = (struct S_frame *)&(HDR_HDLC(p)->hdlc_fc_);
	int seqno = sf->recv_seqno - 1;
	int last_hop = HDR_CMN(p)->last_hop_;
	ARQstate *a = checkState(last_hop);
	
	if (a == 0 || a->SABME_req_ != 2){
		printf("handleRR: No state/connection found for %d\n", last_hop);
		return;
	}

	if (seqno > a->highest_ack_) {  // recvd a new ack
		
		Packet *datapkt = getPkt(a->sendBuf_, seqno);
		if (datapkt != NULL) {
			a->sendBuf_.remove(datapkt);
			Packet::free(datapkt);
			
			// update highest_ack_
			a->highest_ack_ = seqno;
		}
		
		// set retx_timer
		if ((a->t_seqno_-1) > seqno || seqno < a->maxseq_ )
			set_rtx_timer(a);
		
		else
			cancel_rtx_timer(a);
		
	} else { // got duplicate acks
		
		drop(p);
	}
	
	// if had timeouts, should reset it now
	a->ntimeouts_ = 0;
	
	// try to send more
	Packet::free(p);
	sendMuch(a);
	
}