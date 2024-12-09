int DivergenceGraph::insertEdge( const ir::PTXOperand* origin,
	const node_type &toNode, const bool createNewNodes ){
	if( createNewNodes ){
		insertSpecialSource(origin);
	} else if( _specials.find(origin) == _specials.end() ){
		return 1;
	}

	_specials[origin].insert(toNode);
	return 0;
}