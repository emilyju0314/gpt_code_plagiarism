void removeExtraneousCast( ast::ptr<ast::Expr> & expr, const ast::SymbolTable & symtab ) {
			if ( const ast::CastExpr * castExpr = expr.as< ast::CastExpr >() ) {
				if ( typesCompatible( castExpr->arg->result, castExpr->result, symtab ) ) {
					// cast is to the same type as its argument, remove it
					swap_and_save_env( expr, castExpr->arg );
				}
			}
		}