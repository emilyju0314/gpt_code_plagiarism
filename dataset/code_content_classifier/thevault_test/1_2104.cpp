void SubkernelFormationPass::ExtractKernelsPass::runOnKernel(ir::IRKernel& k)
{
	typedef std::vector<ir::ControlFlowGraph::iterator> BlockQueue;
	
	report(" Splitting kernel '" << k.name << "' into sub-kernel regions.");
	report("  - expected region size: " << _expectedRegionSize);
	
	BlockQueue queue;
	KernelVector splitKernels;
	BlockSet region;
	BlockSet encountered;
	BlockSet alreadyAdded;
	BlockSet inEdges;
	BlockSet savedBlocks;
	IdToSubkernelMap idToKernelMap;

	unsigned int currentRegionSize = 0;
	unsigned int kernelId = 0;
	unsigned int spillRegionSize = 0;
		
	std::string originalName = k.name;
	
	ir::PTXKernel& ptx = static_cast<ir::PTXKernel&>(k);

	analysis::DataflowGraph::IteratorMap cfgToDfgMap = _dfg().getCFGtoDFGMap();
	
	// This is the new kernel entry point
	splitKernels.push_back(new ir::PTXKernel(k.name, false, k.module));

	ir::PTXKernel* newKernel = splitKernels.back();

	report(" New kernel name is " << newKernel->name);

	// Start at the entry block	
	ir::ControlFlowGraph::iterator entry = ptx.cfg()->get_entry_block();
	queue.push_back(entry);
	
	while(true)
	{
		// The front of the queue becomes part of the region
		ir::ControlFlowGraph::iterator block = queue.back();
		queue.pop_back();

		// Remove this block from the entering list (if it exists)
		inEdges.erase(block);
		
		// Keep track of all blocks entering the region
		for(ir::ControlFlowGraph::const_edge_pointer_iterator 
			edge = block->in_edges.begin(); 
			edge != block->in_edges.end(); ++edge)
		{
			// skip the entry block
			if((*edge)->head == ptx.cfg()->get_entry_block()) continue;

			// skip the current block
			if((*edge)->head == block) continue;

			// skip blocks in the region
			if(region.count((*edge)->head)) continue;
			
			inEdges.insert((*edge)->head);
		}
		
		// Edges leaving the region become candidates for the next subkernel
		for(ir::ControlFlowGraph::const_edge_pointer_iterator 
			edge = block->out_edges.begin(); 
			edge != block->out_edges.end(); ++edge)
		{
			ir::ControlFlowGraph::iterator tail = (*edge)->tail;

			// skip the exit block
			if(tail == ptx.cfg()->get_exit_block()) continue;
			
			// skip blocks that have already been added
			if(alreadyAdded.count(tail) != 0) continue;
			
			// skip already encountered blocks
			if(!encountered.insert(tail).second) continue;
			
			// push successor blocks
			report("  Queuing up sucessor of block " 
				<< block->id << ", block " << tail->id);
			queue.push_back(tail);
		}

		// Add the block to the new kernel (skip the entry)
		if(block == entry) continue;

		currentRegionSize += block->instructions.size();
		region.insert(block);
		report("  Adding block with id " << block->id 
			<< " to kernel " << newKernel->name);
		idToKernelMap.insert(std::make_pair(block->id,
			KernelAndId(kernelId, newKernel)));
		
		// create a new region if there are enough blocks
		if(currentRegionSize < _expectedRegionSize && !queue.empty()) continue;
		
		entry = createRegion(*newKernel, spillRegionSize, ptx, region,
			inEdges, entry, cfgToDfgMap, alreadyAdded, savedBlocks, _dfg());
		alreadyAdded.insert(region.begin(), region.end());
		
		createScheduler(*newKernel, ptx, savedBlocks, _dfg());

		// restart with a new kernel if there are any blocks left
		if(entry == ptx.cfg()->get_exit_block()) break;
	
		std::stringstream name;
		name << originalName << "_split_" << kernelId++;

		splitKernels.push_back(new ir::PTXKernel(name.str(), true, k.module));
		encountered.clear();
		inEdges.clear();
		region.clear();
		queue.clear();
		savedBlocks.clear();
		queue.push_back(entry);
		currentRegionSize = 0;
		
		newKernel = splitKernels.back();
		report(" New kernel name is " << newKernel->name);
	}

	// Add variables
	for(KernelVector::iterator kernel = splitKernels.begin();
		kernel != splitKernels.end(); ++kernel)
	{
		addVariables(**kernel, k, spillRegionSize, splitKernels.size() > 1);
	}
	
	// Rename 
	updateTailCallTargets(splitKernels, idToKernelMap);

	kernels.insert(std::make_pair(splitKernels.front(),
		std::move(splitKernels)));
}