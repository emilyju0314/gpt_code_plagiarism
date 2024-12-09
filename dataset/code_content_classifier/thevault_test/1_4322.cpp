bool hasDynParams( std::list< Expression* >& params, const TyVarMap &tyVars, const TypeSubstitution *env ) {
			for ( std::list< Expression* >::iterator param = params.begin(); param != params.end(); ++param ) {
				TypeExpr *paramType = dynamic_cast< TypeExpr* >( *param );
				assertf(paramType, "Aggregate parameters should be type expressions");
				if ( isDynType( paramType->get_type(), tyVars, env ) ) return true;
			}
			return false;
		}