void CScheme::LoadFromFile( VPANEL sizingPanel, const char *pFilename, const char *inTag, KeyValues *inKeys )
{
	COM_TimestampedLog( "CScheme::LoadFromFile( %s )", pFilename );

	// the filename is user for lookup comparison purposes
	// must store it normalized
	m_fileName = pFilename;
	V_FixSlashes( m_fileName.Get() );
	
	m_SizingPanel = sizingPanel;

	m_pData = inKeys;
	m_pkvBaseSettings = m_pData->FindKey("BaseSettings", true);
	m_pkvColors = m_pData->FindKey("Colors", true);

	// override the scheme name with the tag name
	KeyValues *name = m_pData->FindKey("Name", true);
	name->SetString("Name", inTag);

	if ( inTag )
	{
		m_tag = inTag;
	}
	else
	{
		Error( "You need to name the scheme (%s)!", m_fileName.String() );
		m_tag = "default";
	}

	// translate format from goldsrc scheme to new scheme
	for (int i = 0; i < ARRAYSIZE(g_SchemeTranslation); i++)
	{
		if (!m_pkvBaseSettings->FindKey(g_SchemeTranslation[i].pchNewEntry, false))
		{
			const char *pchColor;

			if (g_SchemeTranslation[i].pchOldEntry)
			{
				pchColor = LookupSchemeSetting(g_SchemeTranslation[i].pchOldEntry);
			}
			else
			{
				pchColor = g_SchemeTranslation[i].pchDefaultValue;
			}

			Assert( pchColor );

			m_pkvBaseSettings->SetString(g_SchemeTranslation[i].pchNewEntry, pchColor);
		}
	}

	// need to copy tag before loading fonts
	LoadFonts();
	LoadBorders();
}