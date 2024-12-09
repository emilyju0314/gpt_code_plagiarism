bool isThisExpression( const ast::Expr * expr, const ast::DeclWithType * thisParam ) {
		// TODO: there are more complicated ways to pass 'this' to a constructor, e.g. &*, *&, etc.
		if ( auto varExpr = dynamic_cast< const ast::VariableExpr * >( expr ) ) {
			return varExpr->var == thisParam;
		} else if ( auto castExpr = dynamic_cast< const ast::CastExpr * > ( expr ) ) {
			return isThisExpression( castExpr->arg, thisParam );
		}
		return false;
	}