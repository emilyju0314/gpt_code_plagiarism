int DirectionalGraph::eraseEdge( const node_type &fromNode,
	const node_type &toNode, const bool removeIsolatedNodes ){
	/* 1) Test if both nodes of the edge exist */
	if( nodes.find(fromNode) == nodes.end() ){
		return 1;
	}

	if( nodes.find(toNode) == nodes.end() ){
		return 2;
	}

	/* 2) Remove edges */
	outArrows[fromNode].erase(toNode);
	inArrows[toNode].erase(fromNode);

	/* 3) Remove isolated nodes */
	if( removeIsolatedNodes ){
		if( (outArrows[fromNode].size() == 0)
			&& (inArrows[fromNode].size() == 0) ){
			eraseNode(fromNode);
		}

		if( (outArrows[toNode].size() == 0)
			&& (inArrows[toNode].size() == 0) ){
			eraseNode(toNode);
		}
	}

	return 0;
}