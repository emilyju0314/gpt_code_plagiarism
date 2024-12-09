CandidateRef findUnfinishedKindExpression(
			const ast::Expr * untyped, const ast::SymbolTable & symtab, const std::string & kind,
			std::function<bool(const Candidate &)> pred = anyCandidate, ResolvMode mode = {}
		) {
			if ( ! untyped ) return nullptr;

			// xxx - this isn't thread-safe, but should work until we parallelize the resolver
			static unsigned recursion_level = 0;

			++recursion_level;
			ast::TypeEnvironment env;
			CandidateFinder finder{ symtab, env };
			finder.find( untyped, recursion_level == 1 ? mode.atTopLevel() : mode );
			--recursion_level;

			// produce a filtered list of candidates
			CandidateList candidates;
			for ( auto & cand : finder.candidates ) {
				if ( pred( *cand ) ) { candidates.emplace_back( cand ); }
			}

			// produce invalid error if no candidates
			if ( candidates.empty() ) {
				SemanticError( untyped,
					toString( "No reasonable alternatives for ", kind, (kind != "" ? " " : ""),
					"expression: ") );
			}

			// search for cheapest candidate
			CandidateList winners;
			bool seen_undeleted = false;
			for ( CandidateRef & cand : candidates ) {
				int c = winners.empty() ? -1 : cand->cost.compare( winners.front()->cost );

				if ( c > 0 ) continue;  // skip more expensive than winner

				if ( c < 0 ) {
					// reset on new cheapest
					seen_undeleted = ! findDeletedExpr( cand->expr );
					winners.clear();
				} else /* if ( c == 0 ) */ {
					if ( findDeletedExpr( cand->expr ) ) {
						// skip deleted expression if already seen one equivalent-cost not
						if ( seen_undeleted ) continue;
					} else if ( ! seen_undeleted ) {
						// replace list of equivalent-cost deleted expressions with one non-deleted
						winners.clear();
						seen_undeleted = true;
					}
				}

				winners.emplace_back( std::move( cand ) );
			}

			// promote candidate.cvtCost to .cost
			promoteCvtCost( winners );

			// produce ambiguous errors, if applicable
			if ( winners.size() != 1 ) {
				std::ostringstream stream;
				stream << "Cannot choose between " << winners.size() << " alternatives for "
					<< kind << (kind != "" ? " " : "") << "expression\n";
				ast::print( stream, untyped );
				stream << " Alternatives are:\n";
				print( stream, winners, 1 );
				SemanticError( untyped->location, stream.str() );
			}

			// single selected choice
			CandidateRef & choice = winners.front();

			// fail on only expression deleted
			if ( ! seen_undeleted ) {
				SemanticError( untyped->location, choice->expr.get(), "Unique best alternative "
				"includes deleted identifier in " );
			}

			return std::move( choice );
		}