LsPaths* LsRouting::_computeRoutes () 
{
	LsPathsTentative* pTentativePaths = new LsPathsTentative();
	LsPaths* pPaths = new LsPaths() ; // to be returned; 
 
	// step 1. put myself in path
	LsPath toSelf(myNodeId_, 0, myNodeId_); // zero cost, nextHop is myself
	pPaths->insertPathNoChecking(toSelf);
	int newNodeId = myNodeId_;
	LsLinkStateList * ptrLSL = linkStateDatabase_.findPtr(newNodeId);
	if (ptrLSL == NULL )
		// don't have my own linkState
		return pPaths;

	bool done = false;
	// start the loop
	while (! done) {
		// Step 2. for the new node just put in path
		// find the next hop to the new node
		LsNodeIdList nhl;
		LsNodeIdList *nhlp = &nhl; // nextHopeList pointer
    
		if (newNodeId != myNodeId_) {
			// if not looking at my own links, find the next hop 
			// to new node
			nhlp = pPaths->lookupNextHopListPtr(newNodeId);
			if (nhlp == NULL)
				ls_error("computeRoutes: nhlp == NULL \n");
		}
		// for each of it's links
		for (LsLinkStateList::iterator itrLink = ptrLSL->begin();
		     itrLink != ptrLSL->end(); itrLink++) {
			if ((*itrLink).status_ != LS_STATUS_UP)
				// link is not up, skip this link
				continue;
			int dest = (*itrLink).neighborId_;
			int path_cost = (*itrLink).cost_ + 
				pPaths->lookupCost(newNodeId);
			if (pPaths->lookupCost(dest) < path_cost)
				// better path already in paths, 
				// move on to next link
				continue;
			else {
				// else we have a new or equally good path, 
				// LsPathsTentative::insertPath(...) will 
				// take care of checking if the new path is
				// a better or equally good one, etc.
				LsNodeIdList nextHopList;
				if (newNodeId == myNodeId_) {
					// destination is directly connected, 
					// nextHop is itself
					nextHopList.push_back(dest);
					nhlp = &nextHopList;
				}
				pTentativePaths->insertNextHopList(dest, 
						   path_cost, *nhlp);
			}
		}
		done = true;
		// if tentatives empty, terminate;
		while (!pTentativePaths->empty()) {
			// else pop shortest path triple from tentatives
			LsPath sp = pTentativePaths->popShortestPath();
			if (!sp.isValid())
				ls_error (" popShortestPath() failed\n");
			// install the newly found shortest path among 
			// tentatives
			pPaths->insertPath(sp);
			newNodeId = sp.destination;
			ptrLSL = linkStateDatabase_.findPtr(newNodeId);
			if (ptrLSL != NULL) {
				// if we have the link state for the new node
				// break out of inner do loop to continue 
				// computing routes
				done = false;
				break;
			} 
			// else  we don't have linkstate for this new node, 
			// we need to keep popping shortest paths
		}

	} // endof while ( ! done );
	delete pTentativePaths;
	return pPaths;
}