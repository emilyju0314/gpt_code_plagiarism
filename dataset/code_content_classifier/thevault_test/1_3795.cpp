void CEngine::OnGameOverlayActivated( GameOverlayActivated_t *pGameOverlayActivated )
{
	Assert( pGameOverlayActivated );
	if ( pGameOverlayActivated->m_bActive )
		g_pLauncherMgr->ForceSystemCursorVisible();
	else
		g_pLauncherMgr->UnforceSystemCursorVisible();
}