void cte::reinit(const std::vector<factor>& factors) {

	// Set the new factors
	for (size_t i = 0; i < factors.size(); ++i) {
		m_gmo.set_factor(i, factors[i]);
	}

	// Recompute the clique factors
	for (size_t ci = 0; ci != m_clusters.size(); ++ci) {
		detail::node& cl = m_clusters[ci];
		cl.theta = factor(1.0);
		for (size_t j = 0; j < cl.originals.size(); ++j) {
			const factor& f = m_gmo.get_factor(cl.originals[j]);
			cl.theta *= f;
		}
	}

	// Reset the edge messages
	for (vector<detail::edge*>::iterator it = m_edges.begin();
			it != m_edges.end(); ++it) {
		(*it)->reset();
	}

	// Reset the log partition function and beliefs
	m_logz = 0;
	m_beliefs.clear();
	m_beliefs.resize(m_gmo.nvar(), factor(1.0));

	if (m_debug) {
		std::cout << "Initial cluster factors:" << std::endl;
		for (size_t ci = 0; ci != m_clusters.size(); ++ci) {
			detail::node& cl = m_clusters[ci];
			std::cout << " " << ci << " -> " << cl.theta << std::endl;
		}
	}
}