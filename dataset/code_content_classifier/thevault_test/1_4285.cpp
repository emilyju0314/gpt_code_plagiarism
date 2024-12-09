void ConcurrentSueKeyword::addLockUnlockRoutines( StructDecl * decl ) {
		// this routine will be called for all ConcurrentSueKeyword children so only continue if we are a monitor
		if ( !decl->is_monitor() ) return;

		FunctionType * lock_fn_type = new FunctionType( noQualifiers, false );
		FunctionType * unlock_fn_type = new FunctionType( noQualifiers, false );

		// create this ptr parameter for both routines
		ObjectDecl * this_decl = new ObjectDecl(
			"this",
			noStorageClasses,
			LinkageSpec::Cforall,
			nullptr,
			new ReferenceType(
				noQualifiers,
				new StructInstType(
					noQualifiers,
					decl
				)
			),
			nullptr
		);

		lock_fn_type->get_parameters().push_back( this_decl->clone() );
		unlock_fn_type->get_parameters().push_back( this_decl->clone() );
		fixupGenerics(lock_fn_type, decl);
		fixupGenerics(unlock_fn_type, decl);

		delete this_decl;


		//////////////////////////////////////////////////////////////////////
		// The following generates this lock routine for all monitors
		/*
			void lock (monitor_t & this) {
				lock(get_monitor(this));
			}	
		*/
		FunctionDecl * lock_decl = new FunctionDecl(
			"lock",
			Type::Static,
			LinkageSpec::Cforall,
			lock_fn_type,
			nullptr,
			{ },
			Type::Inline
		);

		UntypedExpr * get_monitor_lock =  new UntypedExpr (
			new NameExpr( "get_monitor" ),
			{ new VariableExpr( lock_fn_type->get_parameters().front() ) }
		);

		CompoundStmt * lock_statement = new CompoundStmt();
		lock_statement->push_back(
			new ExprStmt( 
				new UntypedExpr (
					new NameExpr( "lock" ),
					{
						get_monitor_lock
					}
				)
			)
		);
		lock_decl->set_statements( lock_statement );

		//////////////////////////////////////////////////////////////////
		// The following generates this routine for all monitors
		/*
			void unlock (monitor_t & this) {
				unlock(get_monitor(this));
			}	
		*/
		FunctionDecl * unlock_decl = new FunctionDecl(
			"unlock",
			Type::Static,
			LinkageSpec::Cforall,
			unlock_fn_type,
			nullptr,
			{ },
			Type::Inline
		);

		CompoundStmt * unlock_statement = new CompoundStmt();

		UntypedExpr * get_monitor_unlock =  new UntypedExpr (
			new NameExpr( "get_monitor" ),
			{ new VariableExpr( unlock_fn_type->get_parameters().front() ) }
		);

		unlock_statement->push_back(
			new ExprStmt( 
				new UntypedExpr(
					new NameExpr( "unlock" ),
					{
						get_monitor_unlock
					}
				)
			)
		);
		unlock_decl->set_statements( unlock_statement );
		
		// pushes routines to declsToAddAfter to add at a later time
		declsToAddAfter.push_back( lock_decl );
		declsToAddAfter.push_back( unlock_decl );
	}