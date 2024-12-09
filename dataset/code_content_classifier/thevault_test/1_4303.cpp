SatState(
			CandidateRef && c, ast::AssertionSet && nn, InferCache && i, CostVec && cs,
			ast::SymbolTable && syms )
		: cand( std::move( c ) ), need( nn.begin(), nn.end() ), newNeed(), deferred(),
		  inferred( std::move( i ) ), costs( std::move( cs ) ), symtab( std::move( syms ) )
		  { costs.emplace_back( Cost::zero ); }