void FQ::recv(Packet* p, Handler* handler)
{
	hdr_ip* h = hdr_ip::access(p);
	int flowid = h->flowid();
	/* shouldn't be called when head-of-line is pending */
	if (flowid >= MAXFLOW || fs_[flowid].hol_ != 0)
		abort();

	/*
	 * Put this packet at the head-of-line for its queue
	 * and set up scheduling state according to the
	 * standard fair-queueing "finish time" equation.
	 */
	fs_[flowid].hol_ = p;
	double now = Scheduler::instance().clock();
	if (now > fs_[flowid].finishTime_)
		fs_[flowid].finishTime_ = now;
	fs_[flowid].handler_ = handler;
	int size = hdr_cmn::access(p)->size();
	fs_[flowid].delta_ = size * secsPerByte_;

	if (!blocked_) {
		/*
		 * We're not blocked.  Get a packet and send it on.
		 * We perform an extra check because the queue
		 * might drop the packet even if it was
		 * previously empty!  (e.g., RED can do this.)
		 */
		p = deque();
		if (p != 0) {
			blocked_ = 1;
			target_->recv(p, &qh_);
		}
	}
}