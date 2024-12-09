const ast::MemberExpr * isThisMemberExpr( const ast::Expr * expr, const ast::DeclWithType * thisParam ) {
		if ( auto memberExpr = dynamic_cast< const ast::MemberExpr * >( expr ) ) {
			if ( isThisExpression( memberExpr->aggregate, thisParam ) ) {
				return memberExpr;
			}
		} else if ( auto castExpr = dynamic_cast< const ast::CastExpr * >( expr ) ) {
			return isThisMemberExpr( castExpr->arg, thisParam );
		}
		return nullptr;
	}