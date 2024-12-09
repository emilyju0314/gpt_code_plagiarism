bool includesPolyParams( std::list< Expression* >& params, const TypeSubstitution *env ) {
			for ( std::list< Expression* >::iterator param = params.begin(); param != params.end(); ++param ) {
				TypeExpr *paramType = dynamic_cast< TypeExpr* >( *param );
				assertf(paramType, "Aggregate parameters should be type expressions");
				if ( includesPolyType( paramType->get_type(), env ) ) return true;
			}
			return false;
		}