void GameState::ClearSwappingSet() {
	for (int i = 0; i < (int)m_vSwappingSet.size(); i++)
	{
		m_vSwappingSet[i] = nullptr;
	}
	m_vSwappingSet.clear();
	m_vSwappingSet.shrink_to_fit();
	
}