bool DivergenceGraph::eraseNode( const node_iterator &node ){
	if( nodes.find(*node) == nodes.end() ){
		return false;
	}

	_upToDate = false;
	_divergentNodes.erase(*node);

	return DirectionalGraph::eraseNode(*node);
}