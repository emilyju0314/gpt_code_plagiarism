ast::ptr< ast::Expr > findVoidExpression(
			const ast::Expr * untyped, const ast::SymbolTable & symtab
		) {
			ast::TypeEnvironment env;
			ast::ptr< ast::Expr > newExpr = resolveInVoidContext( untyped, symtab, env );
			finishExpr( newExpr, env, untyped->env );
			return newExpr;
		}