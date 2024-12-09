void CSystem::RunFrame()
{
	// record the current frame time
	m_flFrameTime = GetCurrentTime();

	if (m_bStaticWatchForComputerUse)
	{
		// check for mouse movement
		int x, y;
		g_pInput->GetCursorPos(x, y);
		// allow a little slack for jittery mice, don't reset until it's moved more than fifty pixels
		if (abs((x + y) - (m_iStaticMouseOldX + m_iStaticMouseOldY)) > 50)
		{
			m_StaticLastComputerUseTime = Plat_MSTime();
			m_iStaticMouseOldX = x;
			m_iStaticMouseOldY = y;
		}
	}
	
	if ( m_flFrameTime - m_flRegistrySaveTime > REGISTRY_SAVE_INTERVAL )
	{
		m_flRegistrySaveTime = m_flFrameTime;
		SaveRegistryToFile();
//		Registry_RunFrame();
	}
}