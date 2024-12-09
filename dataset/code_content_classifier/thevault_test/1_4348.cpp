void finishExpr(
			ast::ptr< ast::Expr > & expr, const ast::TypeEnvironment & env,
			const ast::TypeSubstitution * oldenv = nullptr
		) {
			// set up new type substitution for expression
			ast::ptr< ast::TypeSubstitution > newenv =
				 oldenv ? oldenv : new ast::TypeSubstitution{};
			env.writeToSubstitution( *newenv.get_and_mutate() );
			expr.get_and_mutate()->env = std::move( newenv );
			// remove unncecessary casts
			StripCasts_new::strip( expr );
		}