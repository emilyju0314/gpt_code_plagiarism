void bte::backward() {

	// Calculate 'backward' messages
	if (m_debug) {
		std::cout << "Begin backward (bottom-up) pass ..." << std::endl;
	}

	vector<std::pair<findex, findex> >::reverse_iterator ri = m_schedule.rbegin();
	double timestamp = timeSystem();
	for (; ri != m_schedule.rend(); ++ri ) {

		// Select backward message m(b->a)
		findex a = (*ri).first;
		findex b = (*ri).second;
		size_t i = m_edge_indeces[a][b]; // edge index

		// Select variables to eliminate
		variable_set VX = m_scopes[b] - m_separators[a][b];

		if (m_debug) {
			std::cout << " - Sending backward msg from "
				<< a << " to " << b << std::endl;
		}

		// Compute the belief at b
		factor bel = calc_belief(b);
		bel /= m_forward[i]; // discard the forward message on the edge
		if (m_task == Task::PR || m_task == Task::MAR) { // marginals
			m_backward[i] = bel.sum(VX);
		} else if (m_task == Task::MAP) { // MAP inference
			m_backward[i] = bel.max(VX);
		} else { // Marginal MAP inference
			for (variable_set::const_iterator vi = VX.begin();
					vi != VX.end(); ++vi) {
				size_t v = vi->label();
				if (m_var_types[v] == false) { // SUM variable
					bel = bel.sum(*vi);
				} else { // MAP variable
					bel = bel.max(*vi);
				}
			}
			m_backward[i] = bel;
		}

		if (m_debug) {
			std::cout << "  - backward msg (" << b << "," << a << "): elim = " << VX << std::endl;
			std::cout << "  -> " << m_backward[i] << std::endl;
		}
	}

	std::cout << "[BTE] Finished backward pass in " << (timeSystem() - timestamp)
			<< " seconds" << std::endl;
}