void graph::triangulate(const std::vector<size_t>& ordering) {

	// set the position map
	size_t n = ordering.size();
	std::vector<size_t> position(n);
	for (size_t i = 0; i < n; ++i) {
		position[ordering[i]] = i;
	}

	// triangulate the graph
	for (size_t i = 0; i < n; ++i) {
		size_t var = ordering[i];
		size_t pos = position[var];

		const set<edge_id>& ns = neighbors(var);
		std::vector<size_t> tmp;
		for (set<edge_id>::const_iterator si = ns.begin(); si != ns.end(); ++si) {
			index ni = (*si).second;
			if (position[ni] > pos) {
				tmp.push_back(ni);
			}
		}

		// connect the earlier neighbors
		int m = (int)tmp.size();
		for (int j = 0; j < m-1; ++j) {
			for (int k = j+1; k < m; ++k) {
				add_edge(tmp[j], tmp[k]);
			}
		}
	}
}