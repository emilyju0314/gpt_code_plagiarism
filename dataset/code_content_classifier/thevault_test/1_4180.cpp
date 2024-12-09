void bte::run() {

	// Start the timer and store it
	m_start_time = timeSystem();

	init();
	propagate();

	// Output solution (UAI output format)
	std::cout << "[BTE] Finished in " << (timeSystem() - m_start_time)
			<< " seconds" << std::endl;


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

			break;
		}
	case Task::MAP: // MAP inference
		{
			std::cout << "Value" << std::endl;
			std::cout << std::fixed << std::setprecision(MERLIN_PRECISION)
				<< m_logz << " (" << std::scientific
				<< std::setprecision(MERLIN_PRECISION)
				<< std::exp(m_logz) << ")" << std::endl;

			std::cout << "MAP" << std::endl;
			std::cout << m_gmo.nvar();
			for (vindex v = 0; v < m_gmo.nvar(); ++v) {
				std::cout << " " << m_best_config[v];
			}
			std::cout << std::endl;

			break;
		}
	case Task::MMAP: // Marginal MAP inference
		{
			std::cout << "Value" << std::endl;
			std::cout << std::fixed << std::setprecision(MERLIN_PRECISION)
				<< m_logz << " (" << std::scientific
				<< std::setprecision(MERLIN_PRECISION)
				<< std::exp(m_logz) << ")" << std::endl;

			std::cout << "MMAP" << std::endl;
			std::cout << m_query.size();
			for (vindex v = 0; v < m_gmo.nvar(); ++v) {
				if (m_var_types[v] == true)
					std::cout << " " << m_best_config[v];
			}
			std::cout << std::endl;

			break;
		}
	}

}