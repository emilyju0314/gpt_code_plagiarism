void filterOverlappingClasses( std::list<EqvClass> & env, const EqvClass & eqvClass ) {
		auto i = env.begin();
		while ( i != env.end() ) {
			auto next = i; ++next;  // save next node in case of erasure

			for ( const auto & v : eqvClass.vars ) {
				if ( i->vars.count( v ) ) {
					env.erase( i );  // remove overlapping class
					break;           // done with this class
				}
			}

			i = next;  // go to next node even if this removed
		}
	}