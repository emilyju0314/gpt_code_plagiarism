ast::ptr< ast::Expr > findKindExpression(
			const ast::Expr * untyped, const ast::SymbolTable & symtab,
			std::function<bool(const Candidate &)> pred = anyCandidate,
			const std::string & kind = "", ResolvMode mode = {}
		) {
			if ( ! untyped ) return {};
			CandidateRef choice =
				findUnfinishedKindExpression( untyped, symtab, kind, pred, mode );
			ResolvExpr::finishExpr( choice->expr, choice->env, untyped->env );
			return std::move( choice->expr );
		}