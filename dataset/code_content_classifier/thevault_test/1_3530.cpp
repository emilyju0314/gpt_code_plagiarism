int CSchemeManager::GetProportionalScaledValueEx( CScheme *pScheme, int normalizedValue )
{
	VPANEL sizing = pScheme->GetSizingPanel();
	if ( !sizing )
	{
		return GetProportionalScaledValue( normalizedValue );
	}

	int w, h;
	g_pIPanel->GetSize( sizing, w, h );
	return GetProportionalScaledValue_( w, h, normalizedValue );
}