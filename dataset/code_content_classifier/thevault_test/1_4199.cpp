std::vector<std::set<size_t> > graph::maximal_cliques(const std::vector<size_t>& ordering) {

	// Create the position map
	size_t n = ordering.size();
	std::vector<size_t> position(n);
	for (size_t i = 0; i < n; ++i) {
		position[ordering[i]] = i;
	}

	// Get all cliques
	std::vector<std::set<size_t> > cliques;
	for (size_t i = 0; i < ordering.size(); ++i) {
		size_t var = ordering[i];
		size_t pos = position[var];
		const set<edge_id>& ns = neighbors(var);

		// form the clique
		std::set<size_t> cli;
		cli.insert(var);
		for (set<edge_id>::const_iterator si = ns.begin();
				si != ns.end(); ++si) {
			size_t ni = (*si).second;
			if (position[ni] > pos) {
				cli.insert(ni);
			}
		}

		cliques.push_back(cli);
	}

	// Keep only maximal cliques
	// remove dominated cliques
	// : A dominates B ( A > B ) iff scope(A) includes scope(B)
	std::vector<std::set<size_t> > clusters;
	for (std::vector<std::set<size_t> >::iterator it1 = cliques.begin();
			it1 != cliques.end(); ++it1) {

		std::set<size_t>& A = *it1;
		bool found = false;
		for (std::vector<std::set<size_t> >::iterator it2 = clusters.begin();
				it2 != clusters.end(); ++it2) {

			std::set<size_t>& B = *it2;
			if ( dominates(B, A) ) {
				found = true;
				break;
			}
		}

		if (!found) {
			for (std::vector<std::set<size_t> >::iterator it3 = clusters.begin();
					it3 != clusters.end();) {

				std::set<size_t>& B = (*it3);
				if ( dominates(A, B) ) {
					clusters.erase(it3);
				} else {
					++it3;
				}
			}

			clusters.push_back(A);
		}
	}

	return clusters;
}