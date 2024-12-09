void graph::init(const vector<variable_set>& fin) {
	for (vector<variable_set>::const_iterator i = fin.begin();
			i != fin.end(); ++i) {
		const variable_set& vs = (*i);
		for (size_t ii = 0; ii < vs.size()-1; ++ii) {
			for (size_t jj = ii+1; jj < vs.size(); ++jj) {
				add_edge(vs[ii].label(), vs[jj].label());
			}
		}
	}
}