bool CEconItemSchema::BInitItemSets( KeyValues *pKVItemSets, CUtlVector<CUtlString> *pVecErrors )
{
	FOR_EACH_TRUE_SUBKEY( pKVItemSets, pKVItemSet )
	{
		const char* setName = pKVItemSet->GetName();

		SCHEMA_INIT_CHECK( setName != NULL, CFmtStr( "All itemsets must have names.") );

		if ( m_mapItemSets.Count() > 0 )
		{
			SCHEMA_INIT_CHECK( GetItemSet( setName ) == NULL, CFmtStr( "Duplicate itemset name (%s) found!", setName ) );
		}

		int idx = m_mapItemSets.Insert( setName );
		SCHEMA_INIT_SUBSTEP( m_mapItemSets[idx].BInitFromKV( pKVItemSet, *this, pVecErrors ) );

		FOR_EACH_VEC( m_mapItemSets[idx].m_ItemEntries, nEntry )
		{
			item_list_entry_t &itemListEntry = m_mapItemSets[idx].m_ItemEntries[ nEntry ];
			CEconItemDefinition *pItemDef = GetItemDefinitionMutable( itemListEntry.m_nItemDef );
			if ( pItemDef )
			{
				pItemDef->AddItemSet( idx );
			}
		}
	}

	return SCHEMA_INIT_SUCCESS();
}