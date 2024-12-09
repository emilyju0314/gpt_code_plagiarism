void makeUnifiableVars( Type *type, OpenVarSet &unifiableVars, AssertionSet &needAssertions ) {
		for ( Type::ForallList::const_iterator tyvar = type->forall.begin(); tyvar != type->forall.end(); ++tyvar ) {
			unifiableVars[ (*tyvar)->get_name() ] = TypeDecl::Data{ *tyvar };
			for ( std::list< DeclarationWithType* >::iterator assert = (*tyvar)->assertions.begin(); assert != (*tyvar)->assertions.end(); ++assert ) {
				needAssertions[ *assert ].isUsed = true;
			}
		}
	}