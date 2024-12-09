void forallFixer( std::list< TypeDecl * > & forall, BaseSyntaxNode * node ) {
		for ( TypeDecl * type : forall ) {
			std::list< DeclarationWithType * > asserts;
			asserts.splice( asserts.end(), type->assertions );
			// expand trait instances into their members
			for ( DeclarationWithType * assertion : asserts ) {
				if ( TraitInstType * traitInst = dynamic_cast< TraitInstType * >( assertion->get_type() ) ) {
					// expand trait instance into all of its members
					expandAssertions( traitInst, back_inserter( type->assertions ) );
					delete traitInst;
				} else {
					// pass other assertions through
					type->assertions.push_back( assertion );
				} // if
			} // for
			// apply FixFunction to every assertion to check for invalid void type
			for ( DeclarationWithType *& assertion : type->assertions ) {
				bool isVoid = fixFunction( assertion );
				if ( isVoid ) {
					SemanticError( node, "invalid type void in assertion of function " );
				} // if
			} // for
			// normalizeAssertions( type->assertions );
		} // for
	}