void
PollAckHandler::handle(Event *e)
{
	PollEvent *pe = (PollEvent *) e;
	Scheduler& s = Scheduler::instance();

	if (mac_->checkInterfaces(MAC_POLLING | MAC_IDLE)) {
		mac_->backoffTime(mac_->backoffBase());
		mac_->mode(MAC_SND);
		mac_->peer(pe->peerMac());
		s.cancel(mac_->pendingPE()); /* cancel pending timeout */
		free(mac_->pendingPE());  // and free the event
		mac_->pendingPE(NULL);
		mac_->send(mac_->pkt()); /* send saved packet */
	}
}