bool matchingTupleStructure( Type * t1, Type * t2 ) {
		TupleType * tuple1 = dynamic_cast< TupleType * >( t1 );
		TupleType * tuple2 = dynamic_cast< TupleType * >( t2 );
		if ( tuple1 && tuple2 ) {
			if ( tuple1->size() != tuple2->size() ) return false;
			for ( auto types : group_iterate( tuple1->get_types(), tuple2->get_types() ) ) {
				if ( ! matchingTupleStructure( std::get<0>( types ), std::get<1>( types ) ) ) return false;
			}
			return true;
		} else if ( ! tuple1 && ! tuple2 ) return true;
		return false;
	}