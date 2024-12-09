void cte::joint_marginal(const variable_set& scope, std::vector<int>& evidence) {

	// Get the cluster that contains the scope
	bool found = false;
	size_t j = 0;
	for (size_t i = 0; i < m_clusters.size(); ++i) {
		detail::node& cl = m_clusters[i];
		variable_set temp = (cl.clique & scope);
		if (temp == scope) {
			found = true;
			j = i;
			break;
		}
	}

	// Safety check
	assert(found);

	// Compute the joint marginal (belief) subject to evidence
	m_marginal = factor(scope, 0.0);
	detail::node& n = m_clusters[j];
	n.belief = n.theta.condition(evidence);
	for (vector<detail::edge*>::iterator ei = n.edges.begin();
			ei != n.edges.end(); ++ei) {
		detail::edge* e = (*ei);
		if (e->second->id == n.id) {
			n.belief *= e->fwd;
		}
		if (e->first->id == n.id) {
			n.belief *= e->bwd;
		}
	}

	// Update the belief entries subject to evidence
	variable_set v_rem;
	for (variable_set::const_iterator vi = n.clique.begin();
			vi != n.clique.end(); ++vi) {
		if (!scope.contains(*vi) && evidence[vi->label()] < 0) {
			v_rem |= *vi;
		}
	}
	n.belief = n.belief.sum(v_rem);

	if (m_debug) {
		std::cout << "[DEBUG] Joint marginal scope: " << m_marginal.vars() << std::endl;
		std::cout << "[DEBUG] Actual belief scope:  " << n.belief << std::endl;
	}

	// Fill in all configurations of the marginal (including the evidence)
	index_config cv1(m_marginal.vars(), true);
	config_index cv2(n.belief.vars(), true);
	for (size_t i = 0; i < m_marginal.num_states(); ++i) {
		std::map<size_t, size_t> config = cv1.convert(i);
		if (is_compatible(config, evidence)) {
			size_t j = cv2.convert(config);
			double v = n.belief.get(j);
			m_marginal.set(i, v);
		} else {
			m_marginal.set(i, 0.0);
		}
	}

	// Normalize by P(evidence)
	m_marginal /= std::exp(m_logz);

	if (m_debug) {
		std::cout << "[DEBUG] Joint marginal: " << m_marginal << std::endl;
	}
}