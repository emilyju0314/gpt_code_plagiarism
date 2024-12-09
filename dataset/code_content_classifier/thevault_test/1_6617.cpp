void
OLSR_MidTimer::expire(Event* e) {
#ifdef MULTIPLE_IFACES_SUPPORT
	agent_->send_mid();
	agent_->set_mid_timer();
#endif
}