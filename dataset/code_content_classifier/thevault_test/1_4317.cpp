size_t functionParameterSize( FunctionType * ftype ) {
		size_t sz = 0;
		for ( DeclarationWithType * p : ftype->get_parameters() ) {
			sz += singleParameterSize( p->get_type() );
		}
		return sz;
	}