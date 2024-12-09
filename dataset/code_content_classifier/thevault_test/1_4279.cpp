const ast::Expr * reconstructMemberExpr( const ast::Expr * member, const ast::Expr * aggr, const CodeLocation & loc ) {
			if ( auto memberExpr = dynamic_cast< const ast::UntypedMemberExpr * >( member ) ) {
				// construct a new UntypedMemberExpr with the correct structure , and recursively
				// expand that member expression.
				ast::Pass< MemberTupleExpander > expander;
				auto inner = new ast::UntypedMemberExpr( loc, memberExpr->aggregate, aggr );
				auto newMemberExpr = new ast::UntypedMemberExpr( loc, memberExpr->member, inner );
				//delete memberExpr;
				return newMemberExpr->accept( expander );
			} else {
				// not a member expression, so there is nothing to do but attach and return
				return new ast::UntypedMemberExpr( loc, member, aggr );
			}
		}