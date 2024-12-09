void RouteLogic::check(int n)
{
	if (n < size_)
		return;

	adj_entry* old = adj_;
	int osize = size_;
	int m = osize;
	if (m == 0)
		m = 16;
	while (m <= n)
		m <<= 1;

	alloc(m);
	for (int i = 0; i < osize; ++i) {
		for (int j = 0; j < osize; ++j)
			adj_[INDEX(i, j, m)].cost =old[INDEX(i, j, osize)].cost;
	}
	size_ = m;
	delete[] old;
}