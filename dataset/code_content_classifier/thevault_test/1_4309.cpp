bool isTuple( const ast::Expr * expr ) {
		if ( ! expr ) return false;
		assert( expr->result );
		return dynamic_cast< const ast::TupleType * >( expr->result->stripReferences() );
	}