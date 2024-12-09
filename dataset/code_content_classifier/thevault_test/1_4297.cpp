bool tyVarCompatible( const TypeDecl::Data & data, const Type * type ) {
		switch ( data.kind ) {
		  case TypeDecl::Dtype:
			// to bind to an object type variable, the type must not be a function type.
			// if the type variable is specified to be a complete type then the incoming
			// type must also be complete
			// xxx - should this also check that type is not a tuple type and that it's not a ttype?
			return ! isFtype( type ) && ( ! data.isComplete || type->isComplete() );
		  case TypeDecl::Ftype:
			return isFtype( type );
		  case TypeDecl::Ttype:
			// ttype unifies with any tuple type
			return dynamic_cast< const TupleType * >( type ) || Tuples::isTtype( type );
		  default:
			assertf(false, "Unhandled tyvar kind: %d", data.kind);
			return false;
		}
	}