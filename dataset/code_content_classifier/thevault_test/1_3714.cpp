bool CMaterialSystem::AddOnLevelShutdownFunc( OnLevelShutdownFunc_t func, void * pUserData )
{
	COnLevelShutdownFunc instance(func, pUserData);
	int i = m_OnLevelShutdownFuncs.Find( instance );
	if (i != -1)
	{
		return false;
	}
	m_OnLevelShutdownFuncs.AddToTail(instance);
	return true;
}