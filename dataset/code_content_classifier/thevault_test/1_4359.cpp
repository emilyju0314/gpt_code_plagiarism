Statement * InitImpl_old::buildListInit( UntypedExpr * dst, std::list< Expression * > & indices ) {
		if ( ! init ) return nullptr;
		CompoundStmt * block = new CompoundStmt();
		build( dst, indices.begin(), indices.end(), init, back_inserter( block->get_kids() ) );
		if ( block->get_kids().empty() ) {
			delete block;
			return nullptr;
		} else {
			init = nullptr; // init was consumed in creating the list init
			return block;
		}
	}