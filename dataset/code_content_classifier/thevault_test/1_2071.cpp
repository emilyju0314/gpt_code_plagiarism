void DivergenceGraph::computeDivergence(){
	report("Computing divergence");
	
	if( _upToDate ){
		report(" already up to date.");
		return;
	}
	/* 1) Clear preview divergent nodes list */
	_divergentNodes.clear();
	node_set newDivergenceNodes;

	/* 2) Set all nodes that are directly dependent of a divergent
		source {tidX and laneid } as divergent */
	{
		std::map<const ir::PTXOperand*, node_set>::iterator
			divergence = _specials.begin();
		std::map<const ir::PTXOperand*, node_set>::iterator
			divergenceEnd = _specials.end();

		for( ; divergence != divergenceEnd; divergence++ ){
			if( isDivSource(divergence->first) ){
				const_node_iterator node = divergence->second.begin();
				const_node_iterator endNode = divergence->second.end();
				
				report(" Node r" << *node
					<< " is a special divergent register.");

				for( ; node != endNode; node++ ){
					newDivergenceNodes.insert(*node);
				}
			}
		}
	}
	{
		/* 3) Set all nodes that are explicitly defined as divergence
			sources as new divergent nodes */

		node_iterator divergence = _divergenceSources.begin();
		node_iterator divergenceEnd = _divergenceSources.end();

		for( ; divergence != divergenceEnd; divergence++ ){
			newDivergenceNodes.insert(*divergence);
			report(" Node r" << *divergence << " is a new divergent register.");
		}
	}

	/* 4) For each new divergent nodes */
	report(" Propagating divergence");
	while( newDivergenceNodes.size() != 0 ){
		node_type originNode = *newDivergenceNodes.begin();
		node_set newReachedNodes = getOutNodesSet(originNode);
		node_iterator current = newReachedNodes.begin();
		node_iterator last = newReachedNodes.end();

		/* 4.1) Set all non divergent nodes that depend directly on
			the divergent node as new divergent nodes */
		for( ; current != last; current++ ){
			if( !isDivNode(*current) ){
				/* 4.1.1) Go to step 4 after step 4.3 until there are
					new divergent nodes */
				report("  propagated from r" << originNode
					<< " -> r" << *current);
				newDivergenceNodes.insert(*current);
			}
		}

		/* 4.2) Insert the node to the divergent nodes list */
		_divergentNodes.insert(originNode);
		/* 4.3) Remove the node from the new divergent list */
		newDivergenceNodes.erase(originNode);
	}
	
	/* 5) propagate convergence from sources */
	node_set notDivergenceNodes;

	{
		/* 5.1) Set all nodes that are explicitly defined as convergence
			that were divergent as not divergent nodes */

		node_iterator convergence = _convergenceSources.begin();
		node_iterator convergenceEnd = _convergenceSources.end();

		for( ; convergence != convergenceEnd; convergence++ ){
			notDivergenceNodes.insert(*convergence);
			node_iterator divergence = _divergentNodes.find(*convergence);
			
			if (divergence != _divergentNodes.end()) {
				notDivergenceNodes.insert(*convergence);
				report(" Node r" << *convergence <<
					" is a new convergent register.");
			}
		}
	}
	
	report(" Propagating convergence");
	while( notDivergenceNodes.size() != 0 ) {
		node_type originNode = *notDivergenceNodes.begin();
		
		_divergentNodes.erase(originNode);
		notDivergenceNodes.erase(originNode);

		/* 5.2) Propagate forward */
		node_set newReachedNodes = getOutNodesSet(originNode);
		node_iterator current = newReachedNodes.begin();
		node_iterator last = newReachedNodes.end();
		for( ; current != last; current++ ) {
			if( isDivNode(*current) ) {
				
				node_set predecessorNodes = getInNodesSet(*current);
				
				bool allConvergent = true;
				
				node_iterator predecessor = predecessorNodes.begin();
				node_iterator lastPredecessor = predecessorNodes.end();

				for( ; predecessor != lastPredecessor; predecessor++ ) {
					if (isDivNode(*predecessor)) {
						allConvergent = false;
						break;
					}
				}
				
				if (!allConvergent) continue;
				
				report("  propagated forward from r" << originNode
					<< " -> r" << *current);
				notDivergenceNodes.insert(*current);
			}
		}
		
		/* 5.3) Propagate backward */
		newReachedNodes = getInNodesSet(originNode);
		current         = newReachedNodes.begin();
		last            = newReachedNodes.end();
		
		for( ; current != last; current++ ) {
			if( isDivNode(*current) ) {
				
				node_set successorNodes = getOutNodesSet(*current);
				
				bool allConvergent = true;
				
				node_iterator successor     = successorNodes.begin();
				node_iterator lastSuccessor = successorNodes.end();

				for( ; successor != lastSuccessor; successor++ ) {
					if (isDivNode(*successor)) {
						allConvergent = false;
						break;
					}
				}
				
				report("  propagated backward from r" << originNode
					<< " -> r" << *current);
				
				if (!allConvergent) {
					_divergentNodes.erase(*current);
					continue;
				}
				
				notDivergenceNodes.insert(*current);
			}
		}
	}

	_upToDate = true;

	#if REPORT_GRAPH > 0
	std::cout << *this;
	#endif
}