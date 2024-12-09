const DirectionalGraph::node_set DirectionalGraph::getInNodesSet(
	const node_type& nodeId ) const {
	if( inArrows.find(nodeId) != inArrows.end() )
		return inArrows.find(nodeId)->second;

	node_set tmp;
	return tmp;
}