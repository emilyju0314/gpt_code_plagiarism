void
Scheduler::dispatch(Event* p, double t)
{
	if (t < clock_) {
		fprintf(stderr, "ns: scheduler going backwards in time from %f to %f.\n", clock_, t);
		abort();
	}

	clock_ = t;
	p->uid_ = -p->uid_;	// being dispatched
	p->handler_->handle(p);	// dispatch
}