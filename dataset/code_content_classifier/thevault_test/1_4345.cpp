void resolveCtorInit( ConstructorInit * ctorInit, const SymTab::Indexer & indexer ) {
		assert( ctorInit );
		PassVisitor<Resolver_old> resolver( indexer );
		ctorInit->accept( resolver );
	}