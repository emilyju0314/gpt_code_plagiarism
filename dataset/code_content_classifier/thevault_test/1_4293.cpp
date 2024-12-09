Type * addrType( const ptr<Type> & type ) {
		if ( auto refType = type.as< ReferenceType >() ) {
			return new ReferenceType( addrType( refType->base ), refType->qualifiers );
		} else {
			return new PointerType( type );
		}
	}