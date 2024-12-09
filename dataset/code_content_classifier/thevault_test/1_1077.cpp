bool CSDKSpectatorGUI::ControlsPresent( void ) const
{
	return ( m_pBlueLabel != NULL &&
		m_pBlueScore != NULL &&
		m_pRedLabel != NULL &&
		m_pRedScore != NULL &&
		m_pTimer != NULL &&
		m_pTimerLabel != NULL &&
		m_pDivider != NULL &&
		m_pExtraInfo != NULL );
}