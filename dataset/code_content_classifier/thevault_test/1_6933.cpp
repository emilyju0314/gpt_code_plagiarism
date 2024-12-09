double
CalendarScheduler::newwidth(int newsize)
{
	if (adjust_new_width_interval_) {
		time_to_newwidth = adjust_new_width_interval_;
		if (avg_gap_ > 0) return avg_gap_*4.0;
	}
	int i;
	int max_bucket = 0; // index of the fullest bucket
	for (i = 1; i < nbuckets_; ++i) {
		if (buckets_[i].count_ > buckets_[max_bucket].count_)
			max_bucket = i;
	}
	int nsamples = buckets_[max_bucket].count_;

	if (nsamples <= 4) return width_;
	
	double nw = buckets_[max_bucket].list_->prev_->time_ 
		- buckets_[max_bucket].list_->time_;
	assert(nw > 0);
	
	nw /= ((newsize < nsamples) ? newsize : nsamples); // min (newsize, nsamples)
	nw *= 4.0;
	
	return nw;
}