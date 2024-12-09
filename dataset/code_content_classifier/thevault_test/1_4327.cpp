void bindAssertion( const DeclarationWithType * decl, AssertionSetValue info, Alternative & alt,
			AssnCandidate & match, InferCache & inferred ) {

		const DeclarationWithType * candidate = match.cdata.id;
		assertf( candidate->uniqueId, "Assertion candidate does not have a unique ID: %s", toString( candidate ).c_str() );

		Expression * varExpr = match.cdata.combine( alt.cvtCost );
		delete varExpr->result;
		varExpr->result = match.adjType->clone();
		if ( match.resnSlot ) { varExpr->resnSlots.push_back( match.resnSlot ); }

		// place newly-inferred assertion in proper place in cache
		inferred[ info.resnSlot ][ decl->get_uniqueId() ] = ParamEntry{
				candidate->uniqueId, candidate->clone(), match.adjType->clone(), decl->get_type()->clone(),
				varExpr };
	}