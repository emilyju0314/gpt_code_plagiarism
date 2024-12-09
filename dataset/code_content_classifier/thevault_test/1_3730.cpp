bool CMaterialSystem::GetRecommendedVideoConfig( KeyValues *pKeyValues )
{
	MaterialLock_t hLock = Lock();
	bool bResult = g_pShaderDeviceMgr->GetRecommendedVideoConfig( m_nAdapter, pKeyValues );
	Unlock( hLock );
	return bResult;
}