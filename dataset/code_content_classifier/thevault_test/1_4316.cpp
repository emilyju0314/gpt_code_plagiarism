size_t singleParameterSize( Type * type ) {
		if ( TupleType * tt = dynamic_cast< TupleType * >( type ) ) {
			size_t sz = 0;
			for ( Type * t : *tt ) {
				sz += singleParameterSize( t );
			}
			return sz;
		} else {
			return 1;
		}
	}