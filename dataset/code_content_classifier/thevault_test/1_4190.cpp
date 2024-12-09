void cte::backward(std::vector<int>& evidence) {
	for (vector<detail::edge*>::reverse_iterator ri = m_messages.rbegin();
			ri != m_messages.rend(); ++ri) {
		detail::edge* e = (*ri);
		e->messageBwd(evidence);

		if (m_debug) {
			std::cout << " <- backward msg from "
				<< e->second->id << " to " << e->first->id
				<< ": " << e->bwd << std::endl;
		}
	}
}