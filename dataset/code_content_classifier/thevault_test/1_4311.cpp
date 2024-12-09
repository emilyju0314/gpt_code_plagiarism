ast::Init * makeInit( const ast::Type * t ) {
		if ( auto inst = dynamic_cast< const ast::StructInstType * >( t ) ) {
			// initizer for empty struct must be empty
			if ( inst->base->members.empty() ) return new ast::ListInit({}, {});
		} else if ( auto inst = dynamic_cast< const ast::UnionInstType * >( t ) ) {
			// initizer for empty union must be empty
			if ( inst->base->members.empty() ) return new ast::ListInit({}, {});
		}

		return new ast::ListInit( {}, { new ast::SingleInit( {}, ast::ConstantExpr::from_int({}, 0) ) } );
	}