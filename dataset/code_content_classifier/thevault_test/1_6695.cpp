void TfrcAgent::recv(Packet *pkt, Handler *)
{
	double now = Scheduler::instance().clock();
	hdr_tfrc_ack *nck = hdr_tfrc_ack::access(pkt);
	//double ts = nck->timestamp_echo;
	double ts = nck->timestamp_echo + nck->timestamp_offset;
	double rate_since_last_report = nck->rate_since_last_report;
	// double NumFeedback_ = nck->NumFeedback_;
	double flost = nck->flost; 
	int losses = nck->losses;
	true_loss_rate_ = nck->true_loss;

	round_id ++ ;
	UrgentFlag = 0;

	if (round_id > 1 && rate_since_last_report > 0) {
		/* compute the max rate for slow-start as two times rcv rate */ 
		ss_maxrate_ = 2*rate_since_last_report*size_;
		if (conservative_) { 
			if (losses >= 1) {
				/* there was a loss in the most recent RTT */
				if (debug_) printf("time: %5.2f losses: %d rate %5.2f\n", 
				  now, losses, rate_since_last_report);
				maxrate_ = rate_since_last_report*size_;
			} else { 
				/* there was no loss in the most recent RTT */
				maxrate_ = scmult_*rate_since_last_report*size_;
			}
			if (debug_) printf("time: %5.2f losses: %d rate %5.2f maxrate: %5.2f\n", now, losses, rate_since_last_report, maxrate_);
		} else 
			maxrate_ = 2*rate_since_last_report*size_;
	} else {
		ss_maxrate_ = 0;
		maxrate_ = 0; 
	}
		
	/* update the round trip time */
	update_rtt (ts, now);

	/* .. and estimate of fair rate */
	if (voip_ != 1) {
		// From RFC 3714:
		// The voip flow gets to send at the same rate as
		//  a TCP flow with 1460-byte packets.
		fsize_ = size_;
	}
	rcvrate = p_to_b(flost, rtt_, tzero_, fsize_, bval_);
	// rcvrate is in bytes per second, based on fairness with a    
	// TCP connection with the same packet size size_.	      
	if (voip_) {
		// Subtract the bandwidth used by headers.
		double temp = rcvrate*(size_/(1.0*headersize_+size_));
		rcvrate = temp;
	}

	/* if we get no more feedback for some time, cut rate in half */
	double t = 2*rtt_ ; 
	if (t < 2*size_/rate_) 
		t = 2*size_/rate_ ; 
	NoFeedbacktimer_.resched(t);
	
	/* if we are in slow start and we just saw a loss */
	/* then come out of slow start */
	if (first_pkt_rcvd == 0) {
		first_pkt_rcvd = 1 ; 
		slowstart();
		nextpkt();
	}
	else {
		if (rate_change_ == SLOW_START) {
			if (flost > 0) {
				rate_change_ = OUT_OF_SLOW_START;
				oldrate_ = rate_ = rcvrate;
			}
			else {
				slowstart();
				nextpkt();
			}
		}
		else {
			if (rcvrate>rate_) 
				increase_rate(flost);
			else 
				decrease_rate ();		
		}
	}
	if (printStatus_) {
		printf("time: %5.2f rate: %5.2f\n", now, rate_);
		double packetrate = rate_ * rtt_ / size_;
		printf("time: %5.2f packetrate: %5.2f\n", now, packetrate);
		double maxrate = maxrate_ * rtt_ / size_;
		printf("time: %5.2f maxrate: %5.2f\n", now, maxrate);
	}
	Packet::free(pkt);
}