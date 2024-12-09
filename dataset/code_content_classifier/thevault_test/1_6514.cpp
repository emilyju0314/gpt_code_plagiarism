int
CBQueue::insert_class(CBQClass *p)
{
	p->cbq_ = this;

	/*
	 * Add to circularly-linked list "active_"
	 *    of peers for the given priority.
	 */

	if (p->pri_ < 0 || p->pri_ > (MAXPRIO-1)) {
		fprintf(stderr, "CBQ class %s has invalid pri %d\n",
			p->name(), p->pri_);
		return (-1);
	}

	if (p->q_ != NULL) {
		// only leaf nodes (which have associated queues)
		// are scheduled
		if (active_[p->pri_] != NULL) {
			p->peer_ = active_[p->pri_]->peer_;
			active_[p->pri_]->peer_ = p;
		} else {
			p->peer_ = p;
			active_[p->pri_] = p;
		}
		if (p->pri_ > maxprio_)
			maxprio_ = p->pri_;
	}

	/*
	 * Compute maxrate from allotment.
	 * convert to bytes/sec
	 *	and store the highest prio# we've seen
	 */

	if (p->allotment_ < 0.0 || p->allotment_ > 1.0) {
		fprintf(stderr, "CBQ class %s has invalid allot %f\n",
			p->name(), p->allotment_);
		return (-1);
	}

	if (link_ == NULL) {
		fprintf(stderr, "CBQ obj %s has no link!\n", name());
		return (-1);
	}
	if (link_->bandwidth() <= 0.0) {
		fprintf(stderr, "CBQ obj %s has invalid link bw %f on link %s\n",
			name(), link_->bandwidth(), link_->name());
		return (-1);
	}

	p->maxrate_ = p->allotment_ * (link_->bandwidth() / 8.0);
	addallot(p->pri_, p->allotment_);

	/*
	 * Add to per-level list
	 *	and store the highest level# we've seen
	 */

	if (p->level_ <= 0 || p->level_ > MAXLEVEL) {
		fprintf(stderr, "CBQ class %s has invalid level %d\n",
			p->name(), p->level_);
		return (-1);
	}

	p->level_peer_ = levels_[p->level_];
	levels_[p->level_] = p;
	if (p->level_ > maxlevel_)
		maxlevel_ = p->level_;

	/*
	 * Check that parent and borrow linkage are acyclic.
	 */
#ifdef notdef
	check_for_cycles(CBQClass::parent);
	check_for_cycles(CBQClass::borrow);
#endif
	return 0;
}