void
OLSR::enque_msg(OLSR_msg& msg, double delay) {
	assert(delay >= 0);
	
	msgs_.push_back(msg);
	OLSR_MsgTimer* timer = new OLSR_MsgTimer(this);
	timer->resched(delay);
}