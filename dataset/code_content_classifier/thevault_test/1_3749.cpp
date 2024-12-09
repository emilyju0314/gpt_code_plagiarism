bool CSystem::SetWatchForComputerUse(bool state)
{
	if (state == m_bStaticWatchForComputerUse)
		return true;

	m_bStaticWatchForComputerUse = state;

	if (m_bStaticWatchForComputerUse)
	{
		// enable watching
	}
	else
	{
		// disable watching
	}
	
	return true;
}