void CSDKSpectatorGUI::ResizeControls( void )
{
	if ( !ControlsPresent() )
		return;

	int x1, y1, w1, t1;
	int x2, y2, w2, t2;

	StoreWidths();

	if ( !ControlsPresent() )
		return;

	// ensure scores are wide enough
	int wCT, hCT, wTer, hTer;
	m_pBlueScore->GetBounds( x1, y1, w1, t1 );
	m_pBlueScore->GetContentSize( wCT, hCT );
	m_pRedScore->GetBounds( x2, y2, w2, t2 );
	m_pRedScore->GetContentSize( wTer, hTer );
	
	int desiredScoreWidth = m_scoreWidth;
	desiredScoreWidth = max( desiredScoreWidth, wCT );
	desiredScoreWidth = max( desiredScoreWidth, wTer );

	int diff = desiredScoreWidth - w1;
	if ( diff != 0 )
	{
		m_pBlueScore->GetBounds( x1, y1, w1, t1 );
		m_pBlueScore->SetBounds( x1 - diff, y1, w1 + diff, t1 );

		m_pRedScore->GetBounds( x1, y1, w1, t1 );
		m_pRedScore->SetBounds( x1 - diff, y1, w1 + diff, t1 );

		m_pBlueLabel->GetPos( x1, y1 );
		m_pBlueLabel->SetPos( x1 - diff, y1 );

		m_pRedLabel->GetPos( x1, y1 );
		m_pRedLabel->SetPos( x1 - diff, y1 );

		m_modifiedWidths = true;
	}

	// ensure extra info is wide enough
	int wExtra, hExtra;
	m_pExtraInfo->GetBounds( x1, y1, w1, t1 );
	m_pExtraInfo->GetContentSize( wExtra, hExtra );

	int desiredExtraWidth = m_extraInfoWidth;
	desiredExtraWidth = max( desiredExtraWidth, wExtra );

	diff = desiredExtraWidth - w1;
	if ( diff != 0 )
	{
		m_pExtraInfo->GetBounds( x1, y1, w1, t1 );
		m_pExtraInfo->SetBounds( x1 - diff, y1, w1 + diff, t1 );

		m_pTimer->GetPos( x1, y1 );
		m_pTimer->SetPos( x1 - diff, y1 );

		m_pTimerLabel->GetPos( x1, y1 );
		m_pTimerLabel->SetPos( x1 - diff, y1 );

		m_pDivider->GetPos( x1, y1 );
		m_pDivider->SetPos( x1 - diff, y1 );

		m_pBlueScore->GetPos( x1, y1 );
		m_pBlueScore->SetPos( x1 - diff, y1 );

		m_pBlueLabel->GetPos( x1, y1 );
		m_pBlueLabel->SetPos( x1 - diff, y1 );

		m_pRedScore->GetPos( x1, y1 );
		m_pRedScore->SetPos( x1 - diff, y1 );

		m_pRedLabel->GetPos( x1, y1 );
		m_pRedLabel->SetPos( x1 - diff, y1 );

		m_modifiedWidths = true;
	}
}