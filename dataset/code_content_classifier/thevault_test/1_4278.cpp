static inline Cost sumCost( const CandidateList & candidates ) {
	Cost total = Cost::zero;
	for ( const CandidateRef & r : candidates ) { total += r->cost; }
	return total;
}