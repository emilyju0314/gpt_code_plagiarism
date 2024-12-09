void addToIndexer( AssertionSet & assertSet, SymTab::Indexer & indexer ) {
		for ( auto&  i : assertSet ) {
			if ( i.second.isUsed ) {
				indexer.addId( i.first );
			}
		}
	}