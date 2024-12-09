ast::ptr< ast::Expr > findSingleExpression(
			const ast::Expr * untyped, const ast::SymbolTable & symtab
		) {
			Stats::ResolveTime::start( untyped );
			auto res = findKindExpression( untyped, symtab );
			Stats::ResolveTime::stop();
			return res;
		}