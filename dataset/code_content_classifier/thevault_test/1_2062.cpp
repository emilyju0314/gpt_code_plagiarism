void DivergenceGraph::insertSpecialSource( const ir::PTXOperand* tid ){
	_upToDate = false;
	if( _specials.find(tid) == _specials.end() ){
		_specials.insert(std::make_pair(tid, node_set()));
	}
}