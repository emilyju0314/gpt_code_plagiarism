bool CEconItemSchema::BInitItemLevels( KeyValues *pKVItemLevels, CUtlVector<CUtlString> *pVecErrors )
{
	m_vecItemLevelingData.RemoveAll();

	// initialize the rewards sections
	if ( NULL != pKVItemLevels )
	{
		FOR_EACH_TRUE_SUBKEY( pKVItemLevels, pKVItemLevelBlock )
		{
			const char *pszLevelBlockName = pKVItemLevelBlock->GetName();
			SCHEMA_INIT_CHECK( GetItemLevelingData( pszLevelBlockName ) == NULL,
				CFmtStr( "Duplicate leveling data block named \"%s\".", pszLevelBlockName ) );

			// Allocate a new structure for this block and assign it. We'll fill in the contents later.
			CUtlVector<CItemLevelingDefinition> *pLevelingData = new CUtlVector<CItemLevelingDefinition>;
			m_vecItemLevelingData.Insert( pszLevelBlockName, pLevelingData );

			FOR_EACH_TRUE_SUBKEY( pKVItemLevelBlock, pKVItemLevel )
			{
				int index = pLevelingData->AddToTail();
				SCHEMA_INIT_SUBSTEP( (*pLevelingData)[index].BInitFromKV( pKVItemLevel, *this, pszLevelBlockName, pVecErrors ) );
			}
		}
	}

	return SCHEMA_INIT_SUCCESS();
}