const ast::Expr * computeExpressionConversionCost(
		const ast::Expr * arg, const ast::Type * paramType, const ast::SymbolTable & symtab, const ast::TypeEnvironment & env, Cost & outCost
	) {
		Cost convCost = computeConversionCost(
				arg->result, paramType, arg->get_lvalue(), symtab, env );
		outCost += convCost;

		// If there is a non-zero conversion cost, ignoring poly cost, then the expression requires
		// conversion. Ignore poly cost for now, since this requires resolution of the cast to
		// infer parameters and this does not currently work for the reason stated below
		Cost tmpCost = convCost;
		tmpCost.incPoly( -tmpCost.get_polyCost() );
		if ( tmpCost != Cost::zero ) {
			ast::ptr< ast::Type > newType = paramType;
			env.apply( newType );
			return new ast::CastExpr{ arg, newType };

			// xxx - *should* be able to resolve this cast, but at the moment pointers are not
			// castable to zero_t, but are implicitly convertible. This is clearly inconsistent,
			// once this is fixed it should be possible to resolve the cast.
			// xxx - this isn't working, it appears because type1 (parameter) is seen as widenable,
			// but it shouldn't be because this makes the conversion from DT* to DT* since
			// commontype(zero_t, DT*) is DT*, rather than nothing

			// CandidateFinder finder{ symtab, env };
			// finder.find( arg, ResolvMode::withAdjustment() );
			// assertf( finder.candidates.size() > 0,
			// 	"Somehow castable expression failed to find alternatives." );
			// assertf( finder.candidates.size() == 1,
			// 	"Somehow got multiple alternatives for known cast expression." );
			// return finder.candidates.front()->expr;
		}

		return arg;
	}