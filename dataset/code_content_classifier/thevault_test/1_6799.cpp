void
PollHandler::handle(Event *e)
{
	PollEvent *pe = (PollEvent *) e;
	Scheduler& s = Scheduler::instance();
	MultihopMac* pm = mac_->peer(); /* sensible val only in MAC_RCV mode */
	
	/*
	 * Send POLLACK if either IDLE or currently receiving 
	 * from same mac as the poller.
	 */
	if (mac_->checkInterfaces(MAC_IDLE)) { // all interfaces must be IDLE
		mac_->mode(MAC_RCV);
		pm = pe->peerMac();
		mac_->peer(pm);
		PollEvent *pae = new PollEvent(pm, mac_); // POLLACK event
		double t = mac_->pollTxtime(MAC_POLLACKSIZE) + 
			max(mac_->tx_rx(), pm->rx_tx());
		s.schedule(pm->pah(), pae, t);
	} else {
		// printf("ignoring poll %d\n", mac_->label());
		// could send NACKPOLL but don't (at least for now)
	}
}