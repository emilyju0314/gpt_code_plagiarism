void DivergenceGraph::unsetAsDiv( const node_type &node ){
	if( _divergenceSources.find(node) != _divergenceSources.end() ){
		_upToDate = false;
		_divergenceSources.erase(node);
	}
}