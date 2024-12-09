void
CBQueue::sched()
{
	Scheduler& s = Scheduler::instance();
	blocked_ = 1;
	s.schedule(&qh_, &intr_, 0);
}