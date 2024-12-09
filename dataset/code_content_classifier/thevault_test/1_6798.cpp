void MultihopMac::poll(Packet *p)
{
	Scheduler& s = Scheduler::instance();
	MultihopMac *pm = (MultihopMac*) getPeerMac(p);
	PollEvent *pe = new PollEvent(pm, this);

	pendingPollEvent_ = new PollEvent(pm, this);
	pkt_ = p->copy();	/* local copy for poll retries */
	double timeout = max(pm->rx_tx(), tx_rx_) + 4*pollTxtime(MAC_POLLSIZE);
	s.schedule(&bh_, pendingPollEvent_, timeout);

	/*  If the other interfaces are idle, then go ahead, else not. */
	if (checkInterfaces(MAC_IDLE)) { 
		mode_ = MAC_POLLING;
		peer_ = pm;
		s.schedule(pm->ph(), (Event *)pe, pollTxtime(MAC_POLLSIZE));
	}
}