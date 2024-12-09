void FixLabelsCore::setLabelsUsage( const ast::Label & label ) {
	if ( labelTable.find( label ) == labelTable.end() ) {
		labelTable[ label ] = nullptr;
	}
}