bool CEngine::Load( bool dedicated, const char *rootdir )
{
	bool success = false;

	// Activate engine
	// NOTE: We must bypass the 'next state' block here for initialization to work properly.
	m_nDLLState = m_nNextDLLState = DLL_ACTIVE;

	if ( Sys_InitGame( 
		g_AppSystemFactory,
		rootdir, 
		game->GetMainWindowAddress(), 
		dedicated ) )
	{
		success = true;

		UpdateMaterialSystemConfig();
	}

	return success;
}