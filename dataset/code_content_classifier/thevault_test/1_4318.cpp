Expression * Specialize::createThunkFunction( FunctionType *funType, Expression *actual, InferredParams *inferParams ) {
		static UniqueName thunkNamer( "_thunk" );

		FunctionType *newType = funType->clone();
		if ( env ) {
			// it is important to replace only occurrences of type variables that occur free in the
			// thunk's type
			env->applyFree( newType );
		} // if
		// create new thunk with same signature as formal type (C linkage, empty body)
		FunctionDecl *thunkFunc = new FunctionDecl( thunkNamer.newName(), Type::StorageClasses(), LinkageSpec::C, newType, new CompoundStmt() );
		thunkFunc->fixUniqueId();

		// thunks may be generated and not used - silence warning with attribute
		thunkFunc->get_attributes().push_back( new Attribute( "unused" ) );

		// Thunks at the global level must be static to avoid collisions between files.
		// (Conversly thunks inside a function must be unique and not static.)
		thunkFunc->storageClasses.is_static = !isInFunction();

		// thread thunk parameters into call to actual function, naming thunk parameters as we go
		UniqueName paramNamer( paramPrefix );
		ApplicationExpr *appExpr = new ApplicationExpr( actual );

		FunctionType * actualType = getFunctionType( actual->get_result() )->clone();
		if ( env ) {
			// need to apply the environment to the actual function's type, since it may itself be polymorphic
			env->apply( actualType );
		}
		std::unique_ptr< FunctionType > actualTypeManager( actualType ); // for RAII
		std::list< DeclarationWithType * >::iterator actualBegin = actualType->get_parameters().begin();
		std::list< DeclarationWithType * >::iterator actualEnd = actualType->get_parameters().end();

		std::list< Expression * > args;
		for ( DeclarationWithType* param : thunkFunc->get_functionType()->get_parameters() ) {
			// name each thunk parameter and explode it - these are then threaded back into the actual function call.
			param->set_name( paramNamer.newName() );
			explodeSimple( new VariableExpr( param ), back_inserter( args ) );
		}

		// walk parameters to the actual function alongside the exploded thunk parameters and restructure the arguments to match the actual parameters.
		std::list< Expression * >::iterator argBegin = args.begin(), argEnd = args.end();
		for ( ; actualBegin != actualEnd; ++actualBegin ) {
			structureArg( (*actualBegin)->get_type(), argBegin, argEnd, back_inserter( appExpr->get_args() ) );
		}

		appExpr->env = TypeSubstitution::newFromExpr( appExpr, env );
		if ( inferParams ) {
			appExpr->inferParams = *inferParams;
		} // if

		// Handle any specializations that may still be present.
		{
			std::string oldParamPrefix = paramPrefix;
			paramPrefix += "p";
			std::list< Declaration * > oldDecls;
			oldDecls.splice( oldDecls.end(), declsToAddBefore );

			appExpr->acceptMutator( *visitor );
			// Write recursive specializations into the thunk body.
			for ( Declaration * decl : declsToAddBefore ) {
				thunkFunc->statements->kids.push_back( new DeclStmt( decl ) );
			}

			declsToAddBefore = std::move( oldDecls );
			paramPrefix = oldParamPrefix;
		}

		// add return (or valueless expression) to the thunk
		Statement *appStmt;
		if ( funType->returnVals.empty() ) {
			appStmt = new ExprStmt( appExpr );
		} else {
			appStmt = new ReturnStmt( appExpr );
		} // if
		thunkFunc->statements->kids.push_back( appStmt );

		// Add the thunk definition (converted to DeclStmt if appproprate).
		declsToAddBefore.push_back( thunkFunc );
		// return address of thunk function as replacement expression
		return new AddressExpr( new VariableExpr( thunkFunc ) );
	}