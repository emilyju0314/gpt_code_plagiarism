void CSDKSpectatorGUI::StoreWidths( void )
{
	if ( !ControlsPresent() )
		return;

	if ( !m_modifiedWidths )
	{
		m_scoreWidth = m_pBlueScore->GetWide();
		int terScoreWidth = m_pRedScore->GetWide();

		m_extraInfoWidth = m_pExtraInfo->GetWide();

		if ( m_scoreWidth != terScoreWidth )
		{
			m_pRedScore = NULL; // We're working with a modified res file.  Don't muck things up playing with positioning.
		}
	}
}