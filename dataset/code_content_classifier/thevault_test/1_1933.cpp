AffineAnalysis::AffineAnalysis() :
	KernelAnalysis("DataflowGraphAnalysis",
	{"DominatorTreeAnalysis", "PostDominatorTreeAnalysis"})

{
	_sa = NULL;
	_aft = NULL;
}