const ast::VariableExpr * DeclReplacer::previsit( const VariableExpr * varExpr ) {
			// xxx - assertions and parameters aren't accounted for in this... (i.e. they aren't inserted into the map when it's made, only DeclStmts are)
			if ( !declMap.count( varExpr->var ) ) return varExpr;

			auto replacement = declMap.at( varExpr->var );
			if ( debug ) {
				std::cerr << "replacing variable reference: "
					<< (void*)varExpr->var.get() << " " << varExpr->var
					<< " with " << (void*)replacement << " " << replacement
					<< std::endl;
			}
			auto nexpr = mutate(varExpr);
			nexpr->var = replacement;
			return nexpr;
		}