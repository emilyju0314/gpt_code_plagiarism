void State::CleanUpAllText() {
	for (int i = 0; i < (int)m_vAllText.size(); i++) {
		delete m_vAllText[i];
		m_vAllText[i] = nullptr;
	}

	m_vAllText.clear();
	m_vAllText.shrink_to_fit();

	textChanged.clear();
	textChanged.shrink_to_fit();

}