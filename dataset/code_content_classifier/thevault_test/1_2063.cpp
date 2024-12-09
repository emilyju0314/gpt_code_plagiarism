void DivergenceGraph::setAsDiv(const node_type &node)
{
	if (_divergenceSources.find(node) == _divergenceSources.end()) {
		_upToDate = false;
		_divergenceSources.insert(node);
	}
	if (nodes.find(node) == nodes.end()) {
		_upToDate = false;
		nodes.insert(node);
	}
}