ast::ptr< ast::Expr > findIntegralExpression(
			const ast::Expr * untyped, const ast::SymbolTable & symtab
		) {
			return findKindExpression( untyped, symtab, hasIntegralType, "condition" );
		}