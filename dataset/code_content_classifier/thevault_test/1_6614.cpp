int IvsReceiver::lossMeter(double timeDiff, u_int32_t seq, double maxrtt)
{
	/*
	 * The congestion signal is calculated here by measuring the loss in a 
	 * given period of packets - if the threshold for lost packets is
	 * passed then signal Congested.  If there are no lost packets,
	 * then we are at UNLOADED, else LOADED
	 */
	/* if sequence number is next, increase expected number */
	
	double now = Scheduler::instance().clock();
	if (nextSeq_ == 0)
		nextSeq_ = seq + 1;
	else if (seq == nextSeq_)
		nextSeq_++;
	else if (seq > nextSeq_) {
#ifdef notdef
		if (trace_ != 0) {
			sprintf(trace_->buffer(), "d %g %d",
				lastPktTime_, seq - nextSeq_);
			trace_->dump();
		}
#endif

		/* This is definitely a hole */
		Mc_Hole* hole = new Mc_Hole;
		hole->time = now;
		hole->start = nextSeq_;
		hole->end = seq - 1;
		hole->next = 0;
		/* Now add it to the list */
		if (head_ == NULL) {
			head_ = hole;
			tail_ = hole;
		} else {
			tail_->next = hole;
			tail_ = hole;
		}
		nextSeq_ = seq + 1;
	} else {
		/* XXX can't happen in current ns simulations */
		fprintf(stderr, "ns: ivs rcvr: seq number went backward\n");
		abort();
	}

	/* update the calculation of the variance in the rtt */
	/* get the time averaged mean of the difference */
	if (timeMean_ == 0)
		timeMean_ = timeDiff;
	else
		timeMean_ = (7 * timeMean_ + timeDiff) / 8;

	timeDiff -= timeMean_;
	if (timeDiff < 0)
		timeDiff = -timeDiff;

	timeVar_ = (7 * timeVar_ + timeDiff) / 8;

	int lostPkts = 0;
	/* 
	 * Check down the list of holes, discarding those that before
	 * now-rttvar-rtt, counting those that fall within
	 * now-rttvar to now-rttvar-rtt
	 */
	if (head_ == 0)
		return (ST_U);

	Mc_Hole *cur = head_, *prev = NULL;

	double validEnd = now - 2 * timeVar_;
	double validStart = validEnd - maxrtt;

	/* for each hole, if it is older than required, dump it */
	/* If it is valid, add the size to the loss count */
	/* Go to the next hole */

	while (cur != NULL) {
		if (cur->time < validStart) {
			if (prev == NULL)
				head_ = cur->next;
			else
				prev->next = cur->next;
			delete cur;
			if (prev == NULL)
				cur = head_;
			else
				cur = prev->next;
		} else {
			if (cur->time < validEnd)
				lostPkts += cur->end - cur->start + 1;
			prev = cur;
			cur = cur->next;
		}
	}

	/*
	 * Update the moving average calculation of the number of holes, if
	 * nowMs is another rtt away
	 */

	double pps = (ipg_ != 0) ? maxrtt / ipg_ : 0.;

/*XXX*/
#ifdef notdef
	if (trace_ != 0) {
		double now = Scheduler::instance().clock();
		sprintf(trace_->buffer(), "%.17g %g", now,
			(double)lostPkts / pps);
		trace_->dump();
	}
#endif

/*XXX*/
#define LOSSCONGTH 15
#define LOSSLOADTH 5
	/* If the rtt is smaller than the ipg, set the thresholds to 0,1,2 */
	if ((pps * LOSSCONGTH) / 100 < 2)
		pps = 200 / LOSSCONGTH;

	if (lostPkts <= (LOSSLOADTH * pps) / 100)
		return (ST_U);
	else if (lostPkts <= (LOSSCONGTH * pps) / 100)
		return (ST_L);
	else
		return (ST_C);
}