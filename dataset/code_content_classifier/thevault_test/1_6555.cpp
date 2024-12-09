void RcvBuffer::add_pkt (int i, double tnow)
{
	Gap	*g, *pg;

	if (exists_pkt (i))
		{
		duplicates_++;
		return;
		}
	// common case first: got what we expected
	if (i == nextpkt_)
		{
		nextpkt_++;
		if (i == maxpkt_ + 1)
			maxpkt_++;
		return;
		}
	// new gap
	if (i > nextpkt_)
		{
		g = new Gap;
		g->start_ = nextpkt_;
		g->end_ = i-1;
		g->time_ = tnow;
		g->next_ = 0;

		if (!gap_)
			gap_ = tail_ = g;
		else	{
			tail_->next_ = g;
			tail_ = g;
			}
		nextpkt_ = i+1;
		return;
		}

	// i < nextpkt_ (a retransmission)

	pkts_recovered_++;

	// is packet part of the first gap?
	if (gap_->start_ <= i && i <= gap_->end_)
		{
		double	d = tnow - gap_->time_;

		if (d > max_delay_)
			max_delay_ = d;
		if (d < min_delay_)
			min_delay_ = d;
		delay_sum_ += d;
		if (i == maxpkt_ + 1)
			{
			maxpkt_++;
			if (++gap_->start_ > gap_->end_)
				{
				g = gap_;
				gap_ = gap_->next_;
				if (gap_)
					maxpkt_ = gap_->start_ - 1;
				else	{
					maxpkt_ = nextpkt_ - 1;
					tail_ = 0;
					}
				delete g;
				}
			return;
			}
		g = gap_;
		}
	else	{
		double	d;

		// locate gap this packet belongs to
		pg = gap_;
		g = gap_->next_;
		while (!(i >= g->start_ && i <= g->end_))
			{
			pg = g;
			g = g->next_;
			}
		d = tnow - g->time_;
		delay_sum_ += d;
		if (d > max_delay_) max_delay_ = d;
		if (d < min_delay_) min_delay_ = d;

		// first packet in gap
		if (g->start_ == i)
			{
			if (++g->start_ > g->end_)
				{
				pg->next_ = g->next_;
				if (tail_ == g)
					tail_ = pg;
				delete g;
				}
			return;
			}
		}
	// last packet in gap
	if (g->end_ == i)
		{
		g->end_--;
		return;
		}
	// a packet in the middle of gap
	pg = new Gap;
	pg->start_ = i+1;
	pg->end_   = g->end_;
	pg->time_  = g->time_;
	pg->next_  = g->next_;

	g->next_ = pg;
	g->end_  = i-1;
	if (tail_ == g)
		tail_ = pg;
}