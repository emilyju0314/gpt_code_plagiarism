bool isTuple( Expression *expr ) {
		if ( ! expr ) return false;
		assert( expr->result );
		return dynamic_cast< TupleType * >( expr->get_result()->stripReferences() );
	}