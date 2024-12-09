bool DivergenceGraph::eraseNode( const node_type &nodeId ){
	_upToDate = false;
	_divergentNodes.erase(nodeId);
	return DirectionalGraph::eraseNode(nodeId);
}