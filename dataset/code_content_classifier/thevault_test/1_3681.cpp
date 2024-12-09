bool CEconItemSchema::BInitQuestRewardLootLists( KeyValues *pKVLootLists, CUtlVector<CUtlString> *pVecErrors )
{
	m_mapQuestRewardLootLists.Purge();

	if ( NULL != pKVLootLists )
	{
		FOR_EACH_SUBKEY( pKVLootLists, pKVList )
		{
			int iListIdx = atoi( pKVList->GetName() );
			const char* strListName = pKVList->GetString();
			m_mapQuestRewardLootLists.Insert( iListIdx, strListName );
		}
	}

	return SCHEMA_INIT_SUCCESS();
}