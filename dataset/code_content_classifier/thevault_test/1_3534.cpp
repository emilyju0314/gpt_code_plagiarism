void CScheme::LoadBorders()
{
	m_pkvBorders = m_pData->FindKey("Borders", true);
	{for ( KeyValues *kv = m_pkvBorders->GetFirstSubKey(); kv != NULL; kv = kv->GetNextKey())
	{
		if (kv->GetDataType() == KeyValues::TYPE_STRING)
		{
			// it's referencing another border, ignore for now
		}
		else
		{
			int i = m_BorderList.AddToTail();

			IBorder *border = NULL;
			const char *pszBorderType = kv->GetString( "bordertype", NULL );
			if ( pszBorderType && pszBorderType[0] )
			{
				if ( !stricmp(pszBorderType,"image") )
				{
					border = new ImageBorder();
				}
				else if ( !stricmp(pszBorderType,"scalable_image") )
				{
					border = new ScalableImageBorder();
				}
				else
				{
					Assert(0);
					// Fall back to the base border type. See below.
					pszBorderType = NULL;
				}
			}

			if ( !pszBorderType || !pszBorderType[0] )
			{
				border = new Border();
			}

			border->SetName(kv->GetName());
			border->ApplySchemeSettings(this, kv);

			m_BorderList[i].border = border;
			m_BorderList[i].bSharedBorder = false;
			m_BorderList[i].borderSymbol = kv->GetNameSymbol();
		}
	}}

	// iterate again to get the border references
	for ( KeyValues *kv = m_pkvBorders->GetFirstSubKey(); kv != NULL; kv = kv->GetNextKey())
	{
		if (kv->GetDataType() == KeyValues::TYPE_STRING)
		{
			// it's referencing another border, find it
			Border *border = (Border *)GetBorder(kv->GetString());
//			const char *str = kv->GetName();
			Assert(border);

			// add an entry that just references the existing border
			int i = m_BorderList.AddToTail();
			m_BorderList[i].border = border;
			m_BorderList[i].bSharedBorder = true;
			m_BorderList[i].borderSymbol = kv->GetNameSymbol();
		}
	}
	
	m_pBaseBorder = GetBorder("BaseBorder");
}