void LabelFixer::previsit( Statement * stmt ) {
		std::list< Label > &labels = stmt->get_labels();

		if ( ! labels.empty() ) {
			// only remember one label for each statement
			Label current = setLabelsDef( labels, stmt );
		} // if
	}