void cte::backward() {
	double timestamp = timeSystem();
	for (vector<detail::edge*>::reverse_iterator ri = m_messages.rbegin();
			ri != m_messages.rend(); ++ri) {
		detail::edge* e = (*ri);
		e->messageBwd();
	}

	if (m_verbose > 0) {
		std::cout << "[CTE] Finished backward pass in " << (timeSystem() - timestamp)
			<< " seconds" << std::endl;
	}
}