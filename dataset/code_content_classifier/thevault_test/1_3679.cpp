bool CEconItemSchema::BInitLootLists( KeyValues *pKVLootLists, KeyValues *pKVRandomAttributeTemplates, CUtlVector<CUtlString> *pVecErrors, bool bServerLists )
{
 	FOR_EACH_TRUE_SUBKEY( pKVLootLists, pKVLootList )
	{
		const char* listName = pKVLootList->GetName();

		SCHEMA_INIT_CHECK( listName != NULL, CFmtStr( "All lootlists must have names.") );

		if ( m_dictLootLists.Count() > 0 )
		{
			SCHEMA_INIT_CHECK( GetLootListByName( listName ) == NULL, CFmtStr( "Duplicate lootlist name (%s) found!", listName ) );
		}

		int idx = m_dictLootLists.Insert( listName );
		SCHEMA_INIT_SUBSTEP( m_dictLootLists[idx].BInitFromKV( pKVLootList, pKVRandomAttributeTemplates, *this, pVecErrors, bServerLists ) );
	}

	return SCHEMA_INIT_SUCCESS();
}