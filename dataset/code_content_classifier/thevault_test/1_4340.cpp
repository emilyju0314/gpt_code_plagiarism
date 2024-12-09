StatementNode * maybe_build_compound( StatementNode * first ) {
	// Optimization: if the control-structure statement is a compound statement, do not wrap it.
	// e.g., if (...) {...} do not wrap the existing compound statement.
	if ( ! dynamic_cast<CompoundStmt *>( first->stmt.get() ) ) { // unique_ptr
		CompoundStmt * cs = new CompoundStmt();
		buildMoveList( first, cs->get_kids() );
		return new StatementNode( cs );
	} // if
	return first;
}