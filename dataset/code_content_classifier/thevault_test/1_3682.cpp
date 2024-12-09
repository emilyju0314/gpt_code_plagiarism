FOR_EACH_DICT_FAST( m_dictWebResources, idx )
	{
		CWebResource* pWebResource = m_dictWebResources[idx];
		if ( !pWebResource )
			continue;

		if ( !pWebResource->m_bOnDemand )
		{
			LoadWebResource( pWebResource->m_strName, NULL );
		}
	}