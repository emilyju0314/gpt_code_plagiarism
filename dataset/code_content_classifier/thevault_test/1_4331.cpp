void finalizeAssertions( ResnState& resn, PruneMap & pruneThresholds, AltList& out ) {
		// prune if cheaper alternative for same key has already been generated
		std::string resKey = pruneKey( resn.alt );
		auto it = pruneThresholds.find( resKey );
		if ( it != pruneThresholds.end() ) {
			if ( it->second < resn.costs ) return;
		} else {
			pruneThresholds.emplace_hint( it, resKey, resn.costs );
		}

		// replace resolution slots with inferred params, add to output
		PassVisitor<InferMatcher> matcher{ resn.inferred };
		resn.alt.expr = resn.alt.expr->acceptMutator( matcher );
		out.emplace_back( resn.alt );
	}