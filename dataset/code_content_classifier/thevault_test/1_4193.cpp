void cte::joint_marginal(const variable_set& scope) {

	// Find the shallowest cliques that contain the scope
	std::vector<int> nodes;
	variable_set temp = scope;
	while (temp.size() > 0) {
		int max_id = -1, max_score = -1;
		std::queue<detail::node*> bfs;
		bfs.push(m_root);
		while (!bfs.empty()) {
			detail::node* c = bfs.front();
			bfs.pop();

			int score = (c->clique & temp).size();
			if (score > 0 && score > max_score) {
				max_score = score;
				max_id = c->id;
			}

			for (vector<detail::node*>::iterator it = c->children.begin();
					it != c->children.end(); ++it) {
				bfs.push(*it);
			}
		}

		assert(max_id >= 0);
		nodes.push_back(max_id);
		temp = temp - (temp & m_clusters[max_id].clique);
	}

	if (m_debug) {
		std::cout << "[DEBUG] Found the shallowest nodes: ";
		std::copy(nodes.begin(), nodes.end(),
				std::ostream_iterator<int>(std::cout, " "));
		std::cout << std::endl;
	}

	// Check if the scope is included in one clique
	if (nodes.size() == 1) { // one clique
		m_marginal = marg(m_clusters[nodes.at(0)].belief, scope);
		m_marginal.normalize();
	} else { // multiple cliques

		// Collect all relevant factors
		vector<factor> factors;
		factors.push_back(m_root->belief);
		for (size_t i = 0; i < nodes.size(); ++i) {
			detail::node* c = &(m_clusters.at(nodes[i]));
			while (c != NULL) {
				for (vector<detail::edge*>::iterator ei = c->edges.begin();
						ei != c->edges.end(); ++ei) {
					detail::edge* e = (*ei);
					if (e->first->id == c->id) {
						factor f = c->belief;
						f /= e->fwd;
						factors.push_back(f);
						break;
					}
				}

				c = c->parent;
				if (c == m_root) {
					break;
				}
			}
		}

		variable_set all_vars, elim_vars;
		for (vector<factor>::iterator fi = factors.begin();
				fi != factors.end(); ++fi) {
			all_vars |= fi->vars();
		}
		elim_vars = (all_vars - scope);

		// Run variables elimination over these factors
		variable_order_t order;
		for (size_t i = 0; i < m_order.size(); ++i) {
			size_t v = m_order[i];
			if (elim_vars.contains(m_gmo.var(v))) {
				order.push_back(v);
			}
		}

		if (m_debug) {
			std::cout << "[DEBUG] All vars: " << all_vars << std::endl;
			std::cout << "[DEBUG] Scope: " << scope << std::endl;
			std::cout << "[DEBUG] Elim: " << elim_vars << std::endl;
			std::cout << "[DEBUG] Factors: " << factors.size() << std::endl;
			std::cout << "[DEBUG] Elim order: ";
			std::copy(order.begin(), order.end(),
					std::ostream_iterator<size_t>(std::cout, " "));
			std::cout << std::endl;
		}

		// Run variable elimination
		for (size_t i = 0; i < order.size(); ++i) {
			size_t v = order[i];
			variable VX = m_gmo.var(v);

			// Collect all factors mentioning VX
			factor f(1.0);
			for (vector<factor>::iterator it = factors.begin();
					it != factors.end();) {
				if (it->variables().contains(VX)) {
					f *= (*it);
					it = factors.erase(it);
				} else {
					++it;
				}
			}

			// Eliminate the variable
			f = elim(f, VX);
			factors.push_back(f);
		}

		// Compute the joint marginal
		m_marginal = factor(1.0);
		for (vector<factor>::iterator it = factors.begin();
				it != factors.end(); ++it) {
			m_marginal *= (*it);
			m_marginal.normalize();
		}
	}
}