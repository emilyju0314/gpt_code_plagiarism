Type * addrExprType( const CodeLocation & loc, const Expr * arg ) {
		assert( arg );
		// If the expression's type is unknown, the address type is unknown.
		if ( nullptr == arg->result ) {
			return nullptr;
		// An lvalue is transformed directly.
		} else if ( arg->get_lvalue() ) {
			return addrType( arg->result );
		// Strip a layer of reference to "create" an lvalue expression.
		} else if ( auto refType = arg->result.as< ReferenceType >() ) {
			return addrType( refType->base );
		} else {
			SemanticError( loc, arg->result.get(),
				"Attempt to take address of non-lvalue expression: " );
		}
	}