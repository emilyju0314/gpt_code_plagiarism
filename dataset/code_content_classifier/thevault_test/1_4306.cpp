std::string pruneKey( const Candidate & cand ) {
		ast::ptr< ast::Type > resType = cand.expr->result;
		cand.env.apply( resType );
		return Mangle::mangle( resType, Mangle::typeMode() );
	}