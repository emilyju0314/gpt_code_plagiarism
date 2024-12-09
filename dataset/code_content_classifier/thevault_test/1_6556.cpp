int RcvBuffer::exists_pkt (int i)
{
	if (i <= maxpkt_)  return 1;
	if (i >= nextpkt_) return 0;

	Gap *g;
	for (g = gap_; g; g = g->next_)
		if (g->start_ <= i && i <= g->end_)
			return 0;
	return 1;
}