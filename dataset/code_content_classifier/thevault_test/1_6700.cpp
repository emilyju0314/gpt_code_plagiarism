void
AckRecons::sendack(int ack, double t)
{
	Packet *ackp = ackTemplate_->copy();
	Scheduler &s = Scheduler::instance();
	hdr_tcp *th = hdr_tcp::access(ackp);
	th->seqno() = ack;
	/* Set no_ts_ in flags because we don't want an rtt sample for this */
	if (th->ts() == hdr_tcp::access(ackp)->ts()) {
		hdr_flags *fh = hdr_flags::access(ackp);
		fh->no_ts_ = 1;
		th->ts_ = s.clock();	/* for debugging purposes only */
	}
	s.schedule((Handler *)this, (Event *)ackp, t);
	ackPending_++;
#ifdef DEBUG
	printf("\t%f\tScheduling ack %d to be sent at %f\n", 
	       s.clock(), ack, s.clock() + t);
#endif
}