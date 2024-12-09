void
OLSR_HelloTimer::expire(Event* e) {
	agent_->send_hello();
	agent_->set_hello_timer();
}