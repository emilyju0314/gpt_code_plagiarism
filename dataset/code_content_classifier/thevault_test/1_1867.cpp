void trace::ConvergenceGenerator::analyzeKernel(const executive::EmulatedKernel &kernel) {
	ir::ControlFlowGraph *cfg = const_cast<ir::ControlFlowGraph *>(kernel.cfg());
	ir::ControlFlowGraph::BlockPointerVector blocks = cfg->executable_sequence();
	ir::ControlFlowGraph::BlockPointerVector::iterator bb_it;
	for (bb_it = blocks.begin(); bb_it != blocks.end(); ++bb_it) {
		Counter counter;
		counter.threads = _entry.blockDim.x * _entry.blockDim.y * _entry.blockDim.z;
		ir::ControlFlowGraph::BasicBlock::InstructionList::const_iterator inst_it =
			(*bb_it)->instructions.begin();
		for (; inst_it != (*bb_it)->instructions.end(); ++inst_it) {
			const ir::Instruction *inst = (*inst_it);
			if (inst && inst->ISA == ir::Instruction::PTX && 
				static_cast<const ir::PTXInstruction *>(inst)->opcode == ir::PTXInstruction::Bar) {
				counter.hasSync = true;
				break;
			}
		}
		counterMap[(*bb_it)->label()] = counter;
	}
	
	Counter counter;
	counter.threads = _entry.blockDim.x * _entry.blockDim.y * _entry.blockDim.z;
	counterMap["entry"] = counter;
}