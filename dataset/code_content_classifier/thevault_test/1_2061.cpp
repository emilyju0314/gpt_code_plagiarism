void DivergenceGraph::clear(){
	DirectionalGraph::clear();
	_divergentNodes.clear();
	_specials.clear();
	_divergenceSources.clear();
	_convergenceSources.clear();
	_upToDate = true;
}