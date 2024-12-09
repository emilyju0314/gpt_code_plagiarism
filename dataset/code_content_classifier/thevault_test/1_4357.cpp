Expression * reconstructMemberExpr( Expression * member, Expression * aggr, CodeLocation & loc ) {
			if ( UntypedMemberExpr * memberExpr = dynamic_cast< UntypedMemberExpr * >( member ) ) {
				// construct a new UntypedMemberExpr with the correct structure , and recursively
				// expand that member expression.
				PassVisitor<MemberTupleExpander> expander;
				UntypedMemberExpr * inner = new UntypedMemberExpr( memberExpr->aggregate, aggr->clone() );
				UntypedMemberExpr * newMemberExpr = new UntypedMemberExpr( memberExpr->member, inner );
				inner->location = newMemberExpr->location = loc;
				memberExpr->member = nullptr;
				memberExpr->aggregate = nullptr;
				delete memberExpr;
				return newMemberExpr->acceptMutator( expander );
			} else {
				// not a member expression, so there is nothing to do but attach and return
				UntypedMemberExpr * newMemberExpr = new UntypedMemberExpr( member, aggr->clone() );
				newMemberExpr->location = loc;
				return newMemberExpr;
			}
		}