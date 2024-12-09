int DivergenceGraph::eraseEdge( const node_type &fromNode,
	const node_type &toNode, const bool removeIsolatedNodes ){
	_upToDate = false;
	if( removeIsolatedNodes ){
		size_t actualNodesCount = nodes.size();
		int result = DirectionalGraph::eraseEdge(
			fromNode, toNode, removeIsolatedNodes);

		if( actualNodesCount == nodes.size() ){
			return result;
		}

		if( nodes.find(fromNode) == nodes.end() ){
			_divergentNodes.erase(fromNode);
		}else{
			_divergentNodes.erase(toNode);
		}

		return result;
	}

	return DirectionalGraph::eraseEdge(fromNode, toNode, removeIsolatedNodes);
}