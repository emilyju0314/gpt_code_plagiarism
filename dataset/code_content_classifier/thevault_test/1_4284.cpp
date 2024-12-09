void ConcurrentSueKeyword::addRoutines( ObjectDecl * field, FunctionDecl * func ) {
		CompoundStmt * statement = new CompoundStmt();
		statement->push_back(
			new ReturnStmt(
				new AddressExpr(
					new MemberExpr(
						field,
						new CastExpr(
							new VariableExpr( func->get_functionType()->get_parameters().front() ),
							func->get_functionType()->get_parameters().front()->get_type()->stripReferences()->clone(),
							false
						)
					)
				)
			)
		);

		FunctionDecl * get_decl = func->clone();

		get_decl->set_statements( statement );

		declsToAddAfter.push_back( get_decl );
	}