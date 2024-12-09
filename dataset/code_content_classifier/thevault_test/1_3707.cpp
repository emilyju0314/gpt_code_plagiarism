void CMaterialSystem::SetAdapter( int nAdapter, int nAdapterFlags )
{
	m_nAdapter = nAdapter;
	m_nAdapterFlags = nAdapterFlags;
	g_pShaderDeviceMgr->GetCurrentModeInfo( &m_nAdapterInfo, m_nAdapter );
}