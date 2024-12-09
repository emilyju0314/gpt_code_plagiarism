void cte::forward(std::vector<int>& evidence) {
	for (vector<detail::edge*>::iterator i = m_messages.begin();
			i != m_messages.end(); ++i) {
		detail::edge* e = (*i);
		e->messageFwd(evidence);

		if (m_debug) {
			std::cout << " -> forward msg from "
				<< e->first->id << " to " << e->second->id
				<< ": " << e->fwd << std::endl;
		}
	}
}