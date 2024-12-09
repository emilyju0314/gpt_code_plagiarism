CandidateList findMinCost( const CandidateList & candidates ) {
		CandidateList out;
		Cost minCost = Cost::infinity;
		for ( const CandidateRef & r : candidates ) {
			if ( r->cost < minCost ) {
				minCost = r->cost;
				out.clear();
				out.emplace_back( r );
			} else if ( r->cost == minCost ) {
				out.emplace_back( r );
			}
		}
		return out;
	}