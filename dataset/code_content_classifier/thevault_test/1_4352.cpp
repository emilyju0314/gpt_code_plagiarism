bool hasIntegralType( const Candidate & i ) {
			const ast::Type * type = i.expr->result;

			if ( auto bt = dynamic_cast< const ast::BasicType * >( type ) ) {
				return bt->isInteger();
			} else if (
				dynamic_cast< const ast::EnumInstType * >( type )
				|| dynamic_cast< const ast::ZeroType * >( type )
				|| dynamic_cast< const ast::OneType * >( type )
			) {
				return true;
			} else return false;
		}