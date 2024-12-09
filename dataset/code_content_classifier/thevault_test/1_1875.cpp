void trace::PerformanceBoundGenerator::analyzeKernel(const executive::EmulatedKernel &kernel) {
	ir::ControlFlowGraph *cfg = const_cast<ir::ControlFlowGraph *>(kernel.cfg());
	ir::ControlFlowGraph::BlockPointerVector blocks = cfg->executable_sequence();
	ir::ControlFlowGraph::BlockPointerVector::iterator bb_it;
	for (bb_it = blocks.begin(); bb_it != blocks.end(); ++bb_it) {
		Counter counter;
		counterMap[(*bb_it)->label()] = counter;
	}
	
	Counter counter;
	counterMap["entry"] = counter;
}