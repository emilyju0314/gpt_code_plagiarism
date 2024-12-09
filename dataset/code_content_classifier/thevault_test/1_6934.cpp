void 
CalendarScheduler::cancel(Event* e)
{
	if (e->uid_ <= 0)	// event not in queue
		return;

	int i = CALENDAR_HASH(e->time_);

	assert(e->prev_->next_ == e);
	assert(e->next_->prev_ == e);

	if (e->next_ == e || 
	    (e->next_->time_ != e->time_ &&
	    (e->prev_->time_ != e->time_))) { 
		--stat_qsize_;
		assert(stat_qsize_ >= 0);
		--buckets_[i].count_;
		assert(buckets_[i].count_ >= 0);
	}

	if (e->next_ == e) {
		assert(buckets_[i].list_ == e);
		buckets_[i].list_ = 0;
	} else {
		e->next_->prev_ = e->prev_;
		e->prev_->next_ = e->next_;
		if (buckets_[i].list_ == e)
			buckets_[i].list_ = e->next_;
	}

	if (buckets_[i].count_ == 0)
		assert(buckets_[i].list_ == 0);

	e->uid_ = -e->uid_;
	e->next_ = e->prev_ = NULL;

	--qsize_;

	return;
}