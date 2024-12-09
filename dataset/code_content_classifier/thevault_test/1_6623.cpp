void
OLSR_MsgTimer::expire(Event* e) {
	agent_->send_pkt();
	delete this;
}