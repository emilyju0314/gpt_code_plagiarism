void bte::update() {

	// update beliefs (marginals) or compute the MAP/MMAP assignment
	if (m_task == Task::MAR) {
		for (vindex v = 0; v < m_gmo.nvar(); ++v) {
			findex c = m_clusters[v][0]; // get a cluster corresp. to current variable
			variable_set vars = m_scopes[c];
			variable VX = m_gmo.var(v);
			variable_set out = vars - VX;

			factor bel = calc_belief(c);
			m_beliefs[v] = marg(bel, VX);
			m_beliefs[v].normalize();
			//m_beliefs[v] /= std::exp(m_logz); // normalize by logZ
		}
	} else if (m_task == Task::MAP) {
		for (variable_order_t::const_reverse_iterator x = m_order.rbegin();
				x != m_order.rend(); ++x) {

			//variable VX = var(*x);
			findex a = m_clusters[*x][0]; // get source bucket of the variable
			factor bel = incoming(a);

			// condition on previous assignment
			for (variable_order_t::const_reverse_iterator y = m_order.rbegin();
				y != m_order.rend(); ++y) {

				if (*y == *x) break;
				variable VY = var(*y);
				if (m_scopes[a].contains(VY)) {
					bel = bel.condition(VY, m_best_config[*y]);
				}
			}
			m_best_config[*x] = bel.argmax();
		}
	} else if (m_task == Task::MMAP) {
		for (variable_order_t::const_reverse_iterator x = m_order.rbegin();
				x != m_order.rend(); ++x) {

			if (m_var_types[*x] == false) break; // stop at first SUM variable
			//variable VX = var(*x);
			findex a = m_clusters[*x][0]; // get source bucket of the variable
			factor bel = incoming(a);

			// condition on previous assignment
			for (variable_order_t::const_reverse_iterator y = m_order.rbegin();
				y != m_order.rend(); ++y) {
				if (*y == *x) break;
				variable VY = var(*y);
				if (m_scopes[a].contains(VY)) {
					bel = bel.condition(VY, m_best_config[*y]);
				}
			}
			m_best_config[*x] = bel.argmax();
		}
	}
}