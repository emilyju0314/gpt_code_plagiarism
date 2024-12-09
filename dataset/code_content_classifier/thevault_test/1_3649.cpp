KeyValues* CEconLootListDefinition::GenerateKeyValues() const
{
	KeyValues* pLootListKV = new KeyValues( m_pszName );

	// Write out our items and weights.
	FOR_EACH_VEC( m_ItemEntries, i )
	{
		const CEconItemDefinition* pItemDef = GetItemSchema()->GetItemDefinition( m_ItemEntries[i].m_nItemDef );
		if ( !pItemDef )
			continue;
		pLootListKV->SetFloat( pItemDef->GetRawDefinition()->GetString( "name" ), m_flWeights[i] );
	}

	// Write out additional drops.

	// Write out random attributes.

	return pLootListKV;
}