void CHudLessonPanel::OnThink()
{
	m_pLabel->SetFgColor(GetFgColor());
	for (int i = 0; i < m_Labels.Count(); i++)
	{
		m_Labels[i]->SetFgColor(GetFgColor());
	}

	// If our label size isn't at the extreme's, we're sliding open / closed
	// This is a hack to get around InvalideLayout() not getting called when
	// m_flLabelSizePercentage is changed via a HudAnimation.
	if ( m_flLabelSizePercentage != 0.0 && m_flLabelSizePercentage != 1.0 || m_bLastLabelUpdateHack )
	{
		m_bLastLabelUpdateHack = (m_flLabelSizePercentage != 0.0 && m_flLabelSizePercentage != 1.0);
		InvalidateLayout();
	}
}