void AffineAnalysis::analyze(ir::IRKernel &k) {
	_kernel = &k;
	AffineTransferFunction::_isFunct = _kernel->function();
	auto dfg = static_cast<DataflowGraph*>(getAnalysis("DataflowGraphAnalysis"));

	dfg->convertToSSAType(DataflowGraph::Gated);

	_sm = new AffineTransferFunction::StateMap;
	_aft = new AffineTransferFunction(*_sm, dfg);
	
	_sa = new SparseAnalysis(dfg, _aft);
	_sa->iterateToFixPoint();
}