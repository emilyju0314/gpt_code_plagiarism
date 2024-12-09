std::map<Label, Statement * > * LabelFixer::resolveJumps() throw ( SemanticErrorException ) {
		std::map< Label, Statement * > *ret = new std::map< Label, Statement * >();
		for ( std::map< Label, Entry * >::iterator i = labelTable.begin(); i != labelTable.end(); ++i ) {
			if ( ! i->second->defined() ) {
				SemanticError( i->first.get_statement()->location, "Use of undefined label: " + i->first.get_name() );
			}
			(*ret)[ i->first ] = i->second->get_definition();
		}

		return ret;
	}