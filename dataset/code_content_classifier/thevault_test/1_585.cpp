Real
compute_jaccard(
	Sizes const & a,
	Sizes const & b
)
{
	Sizes overlap(max(a.size(),b.size()));

	Sizes::iterator const ite(
		set_intersection(a.begin(), a.end(), b.begin(), b.end(), overlap.begin()));
	Size overlap_size(ite - overlap.begin());
	return Real(overlap_size)/(a.size() + b.size() - overlap_size);
}