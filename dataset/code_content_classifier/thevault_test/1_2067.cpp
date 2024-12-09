int DivergenceGraph::insertEdge( const node_type &fromNode,
	const node_type &toNode, const bool createNewNodes ){
	_upToDate = false;
	return DirectionalGraph::insertEdge(fromNode, toNode, createNewNodes);
}