void MultiLevelExitMutator::fixBlock( std::list< Statement * > &kids, bool caseClause ) {
		SemanticErrorException errors;

		for ( std::list< Statement * >::iterator k = kids.begin(); k != kids.end(); k++ ) {
			if ( caseClause ) {
				// once a label is seen, it's no longer a valid fallthrough target
				for ( Label & l : (*k)->labels ) {
					fallthroughLabels.erase( l );
				}
			}

			// aggregate errors since the PassVisitor mutate loop was unrollled
			try {
				*k = (*k)->acceptMutator(*visitor);
			} catch( SemanticErrorException &e ) {
				errors.append( e );
			}

			if ( ! get_breakLabel().empty() ) {
				std::list< Statement * >::iterator next = k+1;
				std::list<Label> ls; ls.push_back( get_breakLabel() );
				kids.insert( next, new NullStmt( ls ) );
				set_breakLabel("");
			} // if
		} // for

		if ( ! errors.isEmpty() ) {
			throw errors;
		}
	}