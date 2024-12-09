void 
Scheduler::schedule(Handler* h, Event* e, double delay)
{
	// handler should ALWAYS be set... if it's not, it's a bug in the caller
	if (!h) {
		fprintf(stderr,
			"Scheduler: attempt to schedule an event with a NULL handler."
			"  Don't DO that at time %f\n", clock_);
		abort();
	};
	
	if (e->uid_ > 0) {
		printf("Scheduler: Event UID not valid!\n\n");
		abort();
	}
	
	if (delay < 0) {
		// You probably don't want to do this
		// (it probably represents a bug in your simulation).
		fprintf(stderr, 
			"warning: ns Scheduler::schedule: scheduling event\n\t"
			"with negative delay (%f) at time %f.\n", delay, clock_);
	}

	if (uid_ < 0) {
		fprintf(stderr, "Scheduler: UID space exhausted!\n");
		abort();
	}
	e->uid_ = uid_++;
	e->handler_ = h;
	double t = clock_ + delay;

	e->time_ = t;
	insert(e);
}