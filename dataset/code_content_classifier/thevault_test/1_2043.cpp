int DirectionalGraph::insertEdge( const node_type &fromNode,
	const node_type &toNode, const bool createNewNodes ){
	/* 1) Tests if can create new nodes */
	if( createNewNodes ){
		/* 1.1) Create ongoing and destination nodes */
		nodes.insert(fromNode);
		nodes.insert(toNode);
	}else{
		/* 1.2) Or test if both nodes exist */
		if( nodes.find(fromNode) == nodes.end() ){
			return 1;
		}

		if( nodes.find(toNode) == nodes.end() ){
			return 2;
		}
	}
	/* 2) Insert / create / update list of ongoing edges for source node
	 * Insert A->B arrow in outArrows: outArrows[A].insert(B) */
	arrow_iterator arrowIt;
	bool createdOutArrowLine = false;
	arrowIt = outArrows.find(fromNode);

	if( arrowIt == outArrows.end() ){
		node_set a;
		outArrows[fromNode] = a;
		createdOutArrowLine = true;
	}

	arrowIt = outArrows.find(fromNode);

	if( arrowIt == outArrows.end() ){
		return 3;
	}

	arrowIt->second.insert(toNode);

	if( outArrows[fromNode].find(toNode) == outArrows[fromNode].end() ){
		if( createdOutArrowLine ){
			outArrows.erase(arrowIt);
		}
		return 4;
	}

	/* 3) Insert / create / update list of incoming edges for destination node
	 * Insert A->B arrow in inArrows: inArrows[B].insert(A) */
	arrowIt = inArrows.find(toNode);

	bool createdInArrowLine = false;

	if( arrowIt == inArrows.end() ){
		node_set a;
		inArrows[toNode] = a;
		createdInArrowLine = true;
	}

	arrowIt = inArrows.find(toNode);

	if( arrowIt == inArrows.end() ){
		if( createdOutArrowLine ){
			outArrows.erase(fromNode);
		}else{
			outArrows[fromNode].erase(toNode);
		}

		return 5;
	}

	inArrows.find(toNode)->second.insert(fromNode);

	if( inArrows[toNode].find(fromNode) == inArrows[toNode].end() ){
		if( createdOutArrowLine ){
			outArrows.erase(fromNode);
		}else{
			outArrows[fromNode].erase(toNode);
		}

		if( createdInArrowLine ){
			inArrows.erase(toNode);
		}

		return 6;
	}

	return 0;
}