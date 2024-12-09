FOR_EACH_VEC( m_ItemEntries, i )
	{
		const CEconItemDefinition* pItemDef = GetItemSchema()->GetItemDefinition( m_ItemEntries[i].m_nItemDef );
		if ( !pItemDef )
			continue;
		pLootListKV->SetFloat( pItemDef->GetRawDefinition()->GetString( "name" ), m_flWeights[i] );
	}