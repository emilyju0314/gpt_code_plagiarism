bool resolveAssertion( AssertionItem & assn, ResnState & resn ) {
		// skip unused assertions
		if ( ! assn.info.isUsed ) return true;

		// lookup candidates for this assertion
		std::list< SymTab::Indexer::IdData > candidates;
		resn.indexer.lookupId( assn.decl->name, candidates );

		// find the candidates that unify with the desired type
		CandidateList matches;
		for ( const auto & cdata : candidates ) {
			const DeclarationWithType * candidate = cdata.id;

			// ignore deleted candidates.
			// NOTE: this behavior is different from main resolver.
			// further investigations might be needed to determine
			// if we should implement the same rule here
			// (i.e. error if unique best match is deleted)
			if (candidate->isDeleted) continue;

			// build independent unification context. for candidate
			AssertionSet have, newNeed;
			TypeEnvironment newEnv{ resn.alt.env };
			OpenVarSet newOpenVars{ resn.alt.openVars };
			Type * adjType = candidate->get_type()->clone();
			adjustExprType( adjType, newEnv, resn.indexer );
			renameTyVars( adjType );

			// keep unifying candidates
			if ( unify( assn.decl->get_type(), adjType, newEnv, newNeed, have, newOpenVars,
					resn.indexer ) ) {
				// set up binding slot for recursive assertions
				UniqueId crntResnSlot = 0;
				if ( ! newNeed.empty() ) {
					crntResnSlot = ++globalResnSlot;
					for ( auto& a : newNeed ) {
						a.second.resnSlot = crntResnSlot;
					}
				}

				matches.emplace_back( cdata, adjType, std::move(newEnv), std::move(have),
					std::move(newNeed), std::move(newOpenVars), crntResnSlot );
			} else {
				delete adjType;
			}
		}

		// break if no suitable assertion
		if ( matches.empty() ) return false;

		// defer if too many suitable assertions
		if ( matches.size() > 1 ) {
			resn.deferred.emplace_back( assn.decl, assn.info, std::move(matches) );
			return true;
		}

		// otherwise bind current match in ongoing scope
		AssnCandidate& match = matches.front();
		addToIndexer( match.have, resn.indexer );
		resn.newNeed.insert( match.need.begin(), match.need.end() );
		resn.alt.env = std::move(match.env);
		resn.alt.openVars = std::move(match.openVars);

		bindAssertion( assn.decl, assn.info, resn.alt, match, resn.inferred );
		return true;
	}