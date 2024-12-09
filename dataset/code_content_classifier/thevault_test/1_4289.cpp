std::string qualifiedName( AggregateDecl * aggr ) {
			std::ostringstream ss;
			qualifiedName( aggr, ss );
			return ss.str();
		}