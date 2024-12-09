bool CMaterialSystem::GetRecommendedConfigurationInfo( int nDXLevel, KeyValues *pKeyValues )
{
	MaterialLock_t hLock = Lock();
	bool bResult = g_pShaderDeviceMgr->GetRecommendedConfigurationInfo( m_nAdapter, nDXLevel, pKeyValues );
	Unlock( hLock );
	return bResult;
}