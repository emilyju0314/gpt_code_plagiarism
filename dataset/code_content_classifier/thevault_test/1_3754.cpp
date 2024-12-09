void CSystem::SaveUserConfigFile()
{
	if (m_pUserConfigData)
	{
		m_pUserConfigData->SaveToFile(g_pFullFileSystem, m_szFileName, m_szPathID);
	}
}