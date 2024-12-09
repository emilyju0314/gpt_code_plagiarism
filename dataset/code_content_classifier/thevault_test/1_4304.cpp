void addToSymbolTable( const ast::AssertionSet & have, ast::SymbolTable & symtab ) {
		for ( auto & i : have ) {
			if ( i.second.isUsed ) { symtab.addId( i.first->var ); }
		}
	}