Label LabelFixer::setLabelsDef( std::list< Label > & llabel, Statement * definition ) {
		assert( definition != 0 );
		assert( llabel.size() > 0 );

		for ( std::list< Label >::iterator i = llabel.begin(); i != llabel.end(); i++ ) {
			Label & l = *i;
			l.set_statement( definition ); // attach statement to the label to be used later
			if ( labelTable.find( l ) == labelTable.end() ) {
				// All labels on this statement need to use the same entry,
				// so this should only be created once.
				// undefined and unused until now, add an entry
				labelTable[ l ] = new Entry( definition );
			} else if ( labelTable[ l ]->defined() ) {
				// defined twice, error
				SemanticError( l.get_statement()->location,
					"Duplicate definition of label: " + l.get_name() );
			} else {
				// used previously, but undefined until now -> link with this entry
				// Question: Is changing objects important?
				delete labelTable[ l ];
				labelTable[ l ] = new Entry( definition );
			} // if
		} // for

		// Produce one of the labels attached to this statement to be temporarily used as the
		// canonical label.
		return labelTable[ llabel.front() ]->get_label();
	}