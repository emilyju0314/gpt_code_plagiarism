void cte::update() {

	// Compute the clique beliefs
	for (size_t i = 0; i < m_clusters.size(); ++i) {
		detail::node& cl = m_clusters[i];
		cl.belief = cl.theta;
		for (vector<detail::edge*>::iterator ei = cl.edges.begin();
				ei != cl.edges.end(); ++ei) {
			detail::edge* e = (*ei);
			if (e->second->id == cl.id) {
				cl.belief *= e->fwd;
			}
			if (e->first->id == cl.id) {
				cl.belief *= e->bwd;
			}
		}
	}

	// Compute the log partition function
	m_logz = std::log(m_root->belief.sum());

	// Compute the marginals
	for (size_t v = 0; v < m_var2clique.size(); ++v) {
		size_t ci = m_var2clique[v];
		detail::node& cl = m_clusters[ci];
		variable VX = m_gmo.var(v);

		m_beliefs[v] = marg(cl.belief, VX);
		m_beliefs[v].normalize(); // normalize
	}
}