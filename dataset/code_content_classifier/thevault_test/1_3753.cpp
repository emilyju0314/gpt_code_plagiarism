void CSystem::SetUserConfigFile(const char *fileName, const char *pathName)
{
	//m_pRegistry->LoadFromFile( g_pFullFileSystem, m_szRegistryPath, NULL );
	
	if (!m_pUserConfigData)
	{
		m_pUserConfigData = new KeyValues("UserConfigData");
	}
	else
	{
		// delete all the existing keys so when we reload from the new file we don't
		// get duplicate entries in our key value
		m_pUserConfigData->Clear();
	}

	Q_strncpy(m_szFileName, fileName, sizeof(m_szFileName));
	Q_strncpy(m_szPathID, pathName, sizeof(m_szPathID));

	// open
	m_pUserConfigData->UsesEscapeSequences( true ); // VGUI may use this
	m_pUserConfigData->LoadFromFile(g_pFullFileSystem, m_szFileName, m_szPathID);
}