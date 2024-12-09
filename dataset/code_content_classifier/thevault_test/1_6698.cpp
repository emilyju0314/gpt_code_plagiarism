void TfrcAgent::reduce_rate_on_no_feedback()
{
	double now = Scheduler::instance().clock();
	if (rate_change_ != SLOW_START)
		// "if" statement added by Sally on 9/25/06,
		// so that an idle report doesn't kick us out of
		// slow-start!
		rate_change_ = RATE_DECREASE; 
	if (oldCode_ || (!all_idle_ && !datalimited_)) {
		// if we are not datalimited
		rate_*=0.5;
	} else if ((datalimited_ || all_idle_) && rate_init_option_ == 1) { 
		// all_idle_: the sender has been datalimited since the 
		//    timer was set
		//  Don't reduce rate below rate_init_ * size_/rtt_.
                if (rate_ > 2.0 * rate_init_ * size_/rtt_ ) {
                        rate_*=0.5;
                } 
	} else if ((datalimited_ || all_idle_) && rate_init_option_ == 2) {
                // Don't reduce rate below the RFC3390 rate.
                if (rate_ > 2.0 * rfc3390(size_) * size_/rtt_ ) {
                        rate_*=0.5;
                } else if ( rate_ > rfc3390(size_) * size_/rtt_ ) {
                        rate_ = rfc3390(size_) * size_/rtt_;
                }
        }
	if (debug_) printf("NO FEEDBACK: time: %5.2f rate: %5.2f all_idle: %d\n", now, rate_, all_idle_);
	UrgentFlag = 1;
	round_id ++ ;
	double t = 2*rtt_ ; 
	// Set the nofeedback timer.
	if (t < 2*size_/rate_) 
		t = 2*size_/rate_ ; 
	NoFeedbacktimer_.resched(t);
	if (datalimited_) {
		all_idle_ = 1;
		if (debug_) printf("Time: %5.2f Datalimited now.\n", now);
	}
	nextpkt();
}