void bindAssertion(
		const ast::VariableExpr * expr, const ast::AssertionSetValue & info, CandidateRef & cand,
		AssnCandidate & match, InferCache & inferred
	) {
		const ast::DeclWithType * candidate = match.cdata.id;
		assertf( candidate->uniqueId,
			"Assertion candidate does not have a unique ID: %s", toString( candidate ).c_str() );

		ast::Expr * varExpr = match.cdata.combine( cand->expr->location, cand->cvtCost );
		varExpr->result = match.adjType;
		if ( match.resnSlot ) { varExpr->inferred.resnSlots().emplace_back( match.resnSlot ); }

		// place newly-inferred assertion in proper location in cache
		inferred[ info.resnSlot ][ expr->var->uniqueId ] = ast::ParamEntry{
			candidate->uniqueId, candidate, match.adjType, expr->result, varExpr };
	}