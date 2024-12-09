void CMaterialSystem::OnLevelShutdown()
{
	// changing contexts away from gameplay
	m_bLevelLoadingComplete = false;

	int nSize = m_OnLevelShutdownFuncs.Count();
	for (int i = 0 ; i < nSize ; ++i)
	{
		COnLevelShutdownFunc & instance = m_OnLevelShutdownFuncs[i];
		instance.m_Func(instance.m_pUserData);
	}
}