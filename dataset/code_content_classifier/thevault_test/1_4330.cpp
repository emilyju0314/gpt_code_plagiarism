std::string pruneKey( const Alternative & alt ) {
		Type* resType = alt.expr->result->clone();
		alt.env.apply( resType );
		std::string resKey = SymTab::Mangler::mangleType( resType );
		delete resType;
		return resKey;
	}