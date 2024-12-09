void cte::forward() {
	double timestamp = timeSystem();
	for (vector<detail::edge*>::iterator i = m_messages.begin();
			i != m_messages.end(); ++i) {
		detail::edge* e = (*i);
		e->messageFwd();
	}

	if (m_verbose > 0) {
		std::cout << "[CTE] Finished forward pass in " << (timeSystem() - timestamp)
			<< " seconds" << std::endl;
	}
}