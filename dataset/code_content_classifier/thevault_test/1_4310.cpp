bool refToTuple( const ast::Expr * expr ) {
		assert( expr->result );
		// check for function returning tuple of reference types
		if ( auto castExpr = dynamic_cast< const ast::CastExpr * >( expr ) ) {
			return refToTuple( castExpr->arg );
		} else {
			return isTuple( expr );
		}
	}