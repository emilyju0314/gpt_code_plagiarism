void
CBQueue::toplevel_departure(CBQClass *cl, double now)
{
	if (toplevel_ >= last_lender_->level_) {
		if ((cl->qmon_->pkts() <= 1) ||
		    last_lender_->undertime_ > now) {
			toplevel_ = MAXLEVEL;
		} else {
			toplevel_ = last_lender_->level_;
		}
	}
}