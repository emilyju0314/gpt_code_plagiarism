void
TimeList::add(double time) {
	TimeElement * new_time, * run, * previous;
	
	if (!head_) {
		// First element on list
		head_ = new TimeElement(time);

	} else {
		// Have to place down on list
		previous = NULL;
		run = head_;
		for (run = head_; run; run = run->next_) {
			if (time == run->time_) {
				// No duplicate times allowed
				break;
			} else if (time < run->time_) {
				if (previous) {
					// Place in middle of list
					new_time = new TimeElement(time);
					new_time->next_ = run;
					previous->next_ = new_time;
				} else {
					// Add to front of list
					new_time = new TimeElement(time);
					new_time->next_ = head_;
					head_ = new_time;
				}
				break;
			}
			previous = run;
		}

		if (!run) {
			// We ran to the end of the list and couldn't place
			// the new time so we have to place it at the end 
			previous->next_ = new TimeElement(time);
		}
	}
}