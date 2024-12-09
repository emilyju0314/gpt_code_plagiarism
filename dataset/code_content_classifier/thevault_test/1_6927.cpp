void HDLC::selectiveRepeatMode(Packet* p)
{
	hdr_cmn *ch = HDR_CMN(p);
	int seq =  ((struct I_frame *)&(HDR_HDLC(p)->hdlc_fc_))->send_seqno;
	bool just_marked_as_seen = FALSE;
	int last_hop = ch->last_hop_;
	ARQstate *a = checkState(last_hop);

	// resize buffers
	// while (seq + 1 - next >= wndmask_) {
	
// 		resize_buffers((wndmask_+1)*2);
// 	}
	
	// strip off hdlc hdr
	ch->size() -= HDLC_HDR_LEN;
	
	if (seq > a->maxseen_) {
		// the packet is the highest we've seen so far
		int i;
		for (i = a->maxseen_ + 1; i < seq; i++) {
			sendSREJ(p, i);
		}

		// we record the packets between the old maximum and
		// the new max as being "unseen" i.e. 0 
		a->maxseen_ = seq;
		
		// place pkt in buffer
		a->seen_[a->maxseen_ & wndmask_] = p;
		
		// necessary so this packet isn't confused as being a duplicate
		just_marked_as_seen = TRUE;
		
	}
	
	if (seq < a->nextpkt_) {
		// Duplicate packet case 1: the packet is to the left edge of
		// the receive window; therefore we must have seen it
		// before
#ifdef DEBUGHDLC
		printf("%f\t Received duplicate packet %d\n",Scheduler::instance().clock(),seq);
#endif
		ack(p);
		drop(p);
		return;
		
	}
	
	int next = a->nextpkt_;
	
	if (seq >= a->nextpkt_ && seq <= a->maxseen_) {
		// next is the left edge of the recv window; maxseen_
		// is the right edge; execute this block if there are
		// missing packets in the recv window AND if current
		// packet falls within those gaps

		if (a->seen_[seq & wndmask_] && !just_marked_as_seen) {
		// Duplicate case 2: the segment has already been
		// recorded as being received (AND not because we just
		// marked it as such)
#ifdef DEBUGHDLC
			printf("%f\t Received duplicate packet %d\n",Scheduler::instance().clock(),seq);
#endif
			ack(p);
			drop(p);
			return;
			
		}

		// record the packet as being seen
		a->seen_[seq & wndmask_] = p;

		while ( a->seen_[next & wndmask_] != NULL ) {
			// this loop first gets executed if seq==next;
			// i.e., this is the next packet in order that
			// we've been waiting for.  the loop sets how
			// many pkt we can now deliver to the
			// application, due to this packet arriving
			// (and the prior arrival of any pkts
			// immediately to the right)

			Packet* rpkt = a->seen_[next & wndmask_];
			a->seen_[next & wndmask_] = 0;
			
			uptarget_ ? sendUp(rpkt) : drop(rpkt);
			
			++next;
		}

		// store the new left edge of the window
		a->nextpkt_ = next;

		// send ack 
		ack(p);
	}
	
}