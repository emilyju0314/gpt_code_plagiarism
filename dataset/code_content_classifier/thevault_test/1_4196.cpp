void cte::run() {

	// Start the timer and store it
	m_start_time = timeSystem();

	init();
	calibrate();
	update();
	if (!m_query.empty()) {
		variable_set scope;
		for (size_t i = 0; i < m_query.size(); ++i) {
			scope |= m_gmo.var(m_query[i]);
		}

		joint_marginal(scope);
	}

	// Output solution (UAI output format)
	if (m_verbose > 0) {
		std::cout << "[CTE] Finished in " << (timeSystem() - m_start_time)
			<< " seconds" << std::endl;
	}

	// Compute the joint marginal given in query

	switch (m_task) {
	case Task::PR:	// partition function
		{
			std::cout << "PR" << std::endl;
			std::cout << std::fixed << std::setprecision(MERLIN_PRECISION)
				<< m_logz << " (" << std::scientific
				<< std::setprecision(MERLIN_PRECISION)
				<< std::exp(m_logz) << ")" << std::endl;

			if (isinf(m_logz)) {
				std::cout << "STATUS" << std::endl;
				std::cout << "false: Inconsistent evidence or underflow" << std::endl;
			} else {
				std::cout << "STATUS" << std::endl;
				std::cout << "true: Consistent evidence" << std::endl;
			}

			break;
		}
	case Task::MAR:	// marginals
		{
			std::cout << "PR" << std::endl;
			std::cout << std::fixed << std::setprecision(MERLIN_PRECISION)
				<< m_logz << " (" << std::scientific
				<< std::setprecision(MERLIN_PRECISION)
				<< std::exp(m_logz) << ")" << std::endl;

			if (isinf(m_logz)) {
				std::cout << "STATUS" << std::endl;
				std::cout << "false: Inconsistent evidence or underflow" << std::endl;
			} else {
				std::cout << "STATUS" << std::endl;
				std::cout << "true: Consistent evidence" << std::endl;
			}

			std::cout << "MAR" << std::endl;
			std::cout << m_gmo.nvar();
			for (vindex v = 0; v < m_gmo.nvar(); ++v) {
				variable VX = m_gmo.var(v);
				std::cout << " " << VX.states();
				for (size_t k = 0; k < VX.states(); ++k) {
					std::cout << " " << std::fixed
						<< std::setprecision(MERLIN_PRECISION)
						<< belief(VX)[k];
				}
			}
			std::cout << std::endl;
			if (!m_query.empty()) {
				variable_set scope = m_marginal.variables();
				std::cout << "JOINT_MAR : " << scope << std::endl;
				std::vector<size_t> dims(scope.size());
				size_t j = 0;
				for (variable_set::const_iterator si = scope.begin(); si != scope.end(); ++si) {
					dims[j++] = (*si).states();
				}

				for (size_t index = 0; index < m_marginal.numel(); ++index) {
					std::vector<size_t> I(dims.size(), 0); // configuration of source variables
					size_t i = index;
					for (size_t v = 0; v < dims.size(); ++v) {
						I[v] = i % dims[v];
						i -= I[v];
						i /= dims[v];
					}

					for (size_t j = 0; j < I.size(); ++j) {
						std::cout << I[j] << " ";
					}
					std::cout << ": " << std::fixed
							<< std::setprecision(MERLIN_PRECISION)
							<< m_marginal[index]
							<< std::endl;
				}
			}

			break;
		}
	default:
		break;
	}
}