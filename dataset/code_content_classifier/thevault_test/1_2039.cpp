bool DirectionalGraph::eraseNode( const node_type &nodeId ){
	arrow_iterator arrows;
	node_iterator nextNode;

	/* 1) Tests if node is present */
	if( nodes.find(nodeId) == nodes.end() )
		return false;

	/* 2) Tests If there are outgoing arrows */
	arrows = outArrows.find(nodeId);
	if( arrows != outArrows.end() ){
		nextNode = arrows->second.begin();

		/* 2.1) Remove this node from each destination's node id source list */
		for( ; nextNode != arrows->second.end(); nextNode++ ){
			arrow_iterator inArrow = inArrows.find(*nextNode);

			if( inArrow != inArrows.end() ){
				inArrows.find(*nextNode)->second.erase(nodeId);
			}
		}
		/* 2.2) Remove this node outgoing list */
		outArrows.erase(nodeId);
	}
	/* 3) Tests If there are incoming arrows */
	arrows = inArrows.find(nodeId);
	if( arrows != inArrows.end() ){
		nextNode = arrows->second.begin();

		/* 3.1) Remove this node from each sources's node id destination list */
		for( ; nextNode != arrows->second.end(); nextNode++ ){
			arrow_iterator outArrow = outArrows.find(*nextNode);

			if( outArrow != outArrows.end() ){
				outArrows.find(*nextNode)->second.erase(nodeId);
			}
		}
		/* 3.2) Remove this node sources list */
		inArrows.erase(nodeId);
	}
	/* 4) Remove the node from the node list */
	nodes.erase(nodeId);

	return true;
}