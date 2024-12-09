bool isCharType( const ast::Type * t ) {
			if ( auto bt = dynamic_cast< const ast::BasicType * >( t ) ) {
				return bt->kind == ast::BasicType::Char
					|| bt->kind == ast::BasicType::SignedChar
					|| bt->kind == ast::BasicType::UnsignedChar;
			}
			return false;
		}