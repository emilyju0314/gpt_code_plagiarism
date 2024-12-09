const ast::Expr * restructureCast(
		ast::ptr< ast::Expr > & arg, const ast::Type * toType, ast::GeneratedFlag isGenerated = ast::GeneratedCast
	) {
		if (
			arg->result->size() > 1
			&& ! toType->isVoid()
			&& ! dynamic_cast< const ast::ReferenceType * >( toType )
		) {
			// Argument is a tuple and the target type is neither void nor a reference. Cast each
			// member of the tuple to its corresponding target type, producing the tuple of those
			// cast expressions. If there are more components of the tuple than components in the
			// target type, then excess components do not come out in the result expression (but
			// UniqueExpr ensures that the side effects will still be produced)
			if ( Tuples::maybeImpureIgnoreUnique( arg ) ) {
				// expressions which may contain side effects require a single unique instance of
				// the expression
				arg = new ast::UniqueExpr{ arg->location, arg };
			}
			std::vector< ast::ptr< ast::Expr > > components;
			for ( unsigned i = 0; i < toType->size(); ++i ) {
				// cast each component
				ast::ptr< ast::Expr > idx = new ast::TupleIndexExpr{ arg->location, arg, i };
				components.emplace_back(
					restructureCast( idx, toType->getComponent( i ), isGenerated ) );
			}
			return new ast::TupleExpr{ arg->location, move( components ) };
		} else {
			// handle normally
			return new ast::CastExpr{ arg->location, arg, toType, isGenerated };
		}
	}