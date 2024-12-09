bool needsPolySpecialization( Type *formalType, Type *actualType, const TypeSubstitution *env ) {
		if ( env ) {
			using namespace ResolvExpr;
			OpenVarSet openVars, closedVars;
			AssertionSet need, have;
			findOpenVars( formalType, openVars, closedVars, need, have, false );
			findOpenVars( actualType, openVars, closedVars, need, have, true );
			for ( OpenVarSet::const_iterator openVar = openVars.begin(); openVar != openVars.end(); ++openVar ) {
				Type *boundType = env->lookup( openVar->first );
				if ( ! boundType ) continue;
				if ( TypeInstType *typeInst = dynamic_cast< TypeInstType* >( boundType ) ) {
					// bound to another type variable
					if ( closedVars.find( typeInst->get_name() ) == closedVars.end() ) {
						// bound to a closed variable => must specialize
						return true;
					} // if
				} else {
					// variable is bound to a concrete type => must specialize
					return true;
				} // if
			} // for
			// none of the type variables are bound
			return false;
		} else {
			// no env
			return false;
		} // if
	}