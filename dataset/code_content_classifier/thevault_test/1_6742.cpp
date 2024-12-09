void RTPAgent::rate_change()
{
	rtp_timer_.force_cancel();
	
	double t = lastpkttime_ + interval_;
	
	double now = Scheduler::instance().clock();
	if ( t > now)
		rtp_timer_.resched(t - now);
	else {
		sendpkt();
		rtp_timer_.resched(interval_);
	}
}