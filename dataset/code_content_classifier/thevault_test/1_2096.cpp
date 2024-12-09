void SyncEliminationPass::runOnKernel(ir::IRKernel& k)
{
	Analysis* div_structure = getAnalysis("DivergenceAnalysis");
	assert(div_structure != 0);

	const analysis::DivergenceAnalysis *divAnalysis =
		static_cast<analysis::DivergenceAnalysis*>(div_structure);

	Analysis* dfg_structure = getAnalysis("DataflowGraphAnalysis");
	assert(dfg_structure != 0);

	analysis::DataflowGraph& dfg =
		*static_cast<analysis::DataflowGraph*>(dfg_structure);

        // Ocelot uses guards to represent the first and last basic block of
        // each kernel. These special blocks hold no instruction; hence, we
        // do not need to go through them.
	analysis::DataflowGraph::iterator block = ++dfg.begin();
	analysis::DataflowGraph::iterator blockEnd = --dfg.end();

	for (; block != blockEnd; block++) {
		if (!divAnalysis->isDivBlock(block)) {
			ir::PTXInstruction *ptxInst
				= static_cast<ir::PTXInstruction*> (
					block->block()->instructions.back());
			if (ptxInst->opcode == ir::PTXInstruction::Bra) {
				ptxInst->uni = true;
			}
		}
	}
}