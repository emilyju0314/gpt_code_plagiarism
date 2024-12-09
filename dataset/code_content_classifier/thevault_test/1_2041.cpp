const DirectionalGraph::node_set DirectionalGraph::getOutNodesSet(
	const node_type& nodeId ) const{
	if( outArrows.find(nodeId) != outArrows.end() )
		return outArrows.find(nodeId)->second;

	node_set tmp;
	return tmp;
}