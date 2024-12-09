bool CEconItemSchema::BInitRevolvingLootLists( KeyValues *pKVLootLists, CUtlVector<CUtlString> *pVecErrors )
{
	FOR_EACH_SUBKEY( pKVLootLists, pKVList )
	{
		int iListIdx = atoi( pKVList->GetName() );
		const char* strListName = pKVList->GetString();
		m_mapRevolvingLootLists.Insert( iListIdx, strListName );
	}

	return SCHEMA_INIT_SUCCESS();
}