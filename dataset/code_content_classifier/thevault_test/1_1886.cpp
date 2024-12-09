void PostdominatorTree::computeDT() {
	int end_node = blocksToIndex[cfg->get_exit_block()];

	bool changed = true;
	p_dom[end_node] = end_node;

	report( " Computing tree" );

	while (changed) {
		changed = false;

		// post-order
		for (int b_ind = 0; b_ind < (int)blocks.size(); b_ind++) {
			if (b_ind == end_node)  continue;

			ir::ControlFlowGraph::iterator b = blocks[b_ind];
			assert(!b->successors.empty());
			int new_pdom = 0;
			bool processed = false;

			ir::ControlFlowGraph::pointer_iterator 
				succ_it = b->successors.begin();
			for (; succ_it != b->successors.end(); ++succ_it) {
				int p = blocksToIndex[*succ_it];
				assert(p<(int)p_dom.size());
				if (p_dom[p] != -1) {
					if( !processed ) {
						new_pdom = p;
						processed = true;
					}
					else {
						new_pdom = intersect(p, new_pdom);
					}
				}
			}
		
			if( processed ) {			
				if (p_dom[b_ind] != new_pdom) {
					p_dom[b_ind] = new_pdom;
					changed = true;
				}
			}
		}
	}
	
	dominated.resize(blocks.size());
	for (int n = 0; n < (int)blocks.size(); n++) {
		if (p_dom[n] >= 0) {
			dominated[p_dom[n]].push_back(n);
		}
	}
	
	report(" Computing frontiers")
	
	frontiers.resize(blocks.size());
	for (int b_ind = 0; b_ind < (int)blocks.size(); b_ind++) {
	
		ir::ControlFlowGraph::iterator block = blocks[b_ind];
			
		if(block->successors.size() < 2) continue;

		typedef std::unordered_set<int> BasicBlockSet;
		
		BasicBlockSet blocksWithThisBlockInTheirFrontier;
		
		for (auto successor : block->successors) {
			auto runner = successor;
			
			while (runner != getPostDominator(block)) {
				blocksWithThisBlockInTheirFrontier.insert(
					blocksToIndex[runner]);
				
				runner = getPostDominator(runner);
			}
		}
		
		for (auto frontierBlock : blocksWithThisBlockInTheirFrontier) {
			frontiers[b_ind].push_back(frontierBlock);
		}
	}
}