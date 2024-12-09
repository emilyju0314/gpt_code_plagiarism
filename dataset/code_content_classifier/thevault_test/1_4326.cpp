ResnState( ResnState && o, IterateFlag )
		: alt(std::move(o.alt)), need(o.newNeed.begin(), o.newNeed.end()), newNeed(), deferred(),
		  inferred(std::move(o.inferred)), costs(o.costs), indexer(o.indexer) {
			costs.emplace_back( Cost::zero );
		}