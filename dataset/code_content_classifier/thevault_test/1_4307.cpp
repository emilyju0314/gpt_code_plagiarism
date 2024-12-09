void finalizeAssertions(
		CandidateRef & cand, InferCache & inferred, PruneMap & thresholds, CostVec && costs,
		CandidateList & out
	) {
		// prune if cheaper alternative for same key has already been generated
		std::string key = pruneKey( *cand );
		auto it = thresholds.find( key );
		if ( it != thresholds.end() ) {
			if ( it->second < costs ) return;
		} else {
			thresholds.emplace_hint( it, key, std::move( costs ) );
		}

		// replace resolution slots with inferred parameters, add to output
		ast::Pass< InferMatcher > matcher{ inferred };
		cand->expr = cand->expr->accept( matcher );
		out.emplace_back( cand );
	}