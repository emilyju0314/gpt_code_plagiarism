void
TimerHandler::sched(double delay)
{
	if (status_ != TIMER_IDLE) {
		fprintf(stderr,"Couldn't schedule timer");
		abort();
	}
	_sched(delay);
	status_ = TIMER_PENDING;
}