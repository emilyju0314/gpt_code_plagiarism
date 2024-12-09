void bte::forward() {

	if (m_debug) {
		std::cout << "Begin forward (top-down) pass ..." << std::endl;
	}

	m_logz = 0; // reset the log parition function
	double timestamp = timeSystem();
	for (variable_order_t::const_iterator x = m_order.begin(); x != m_order.end(); ++x) {

		if (m_debug) {
			std::cout << " - Eliminating var " << *x
					<< (m_var_types[*x] ? " (MAP)\n" : " (SUM)\n");
		}

		// Generate forward messages
		variable VX = var(*x);
		findex a = m_clusters[*x][0]; // get source bucket of the variable
		if (m_out[a].size() > 0) {
			findex b = *(m_out[a].begin()); // destination bucket
			size_t ei = m_edge_indeces[a][b]; // edge index (for message)
			if (m_var_types[*x] == false) { // SUM variable
				m_forward[ei] = incoming(a, ei).sum(VX);
			} else { // MAP variable
				m_forward[ei] = incoming(a, ei).max(VX);
			}

			if (m_debug) {
				std::cout << "  forward msg (" << a << "," << b << "): elim = " << VX << " -> ";
				std::cout << m_forward[ei] << std::endl;
			}
		}
	} // done

	// Compute log partition function logZ or MAP/MMAP value
	factor F(0.0);
	for (flist::const_iterator ci = m_roots.begin();
			ci != m_roots.end(); ++ci) {

		factor bel = calc_belief(*ci);
		std::map<size_t, size_t>::iterator mi = m_cluster2var.find(*ci);
		assert(mi != m_cluster2var.end());
		size_t v = mi->second;
		if (m_var_types[v] == false) { // SUM variable
			F += log( bel.sum());
		} else { // MAP variable
			F += log( bel.max() );
		}
	}

	// Partition function or MAP/MMAP value
	m_logz += F.max();

	std::cout << "[BTE] Finished forward pass in " << (timeSystem() - timestamp)
			<< " seconds" << std::endl;
}