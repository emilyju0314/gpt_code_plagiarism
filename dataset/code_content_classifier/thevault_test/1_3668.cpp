bool CEconItemSchema::BInitDefinitionPrefabs( KeyValues *pKVPrefabs, CUtlVector<CUtlString> *pVecErrors )
{
	FOR_EACH_TRUE_SUBKEY( pKVPrefabs, pKVPrefab )
	{
		const char *pszPrefabName = pKVPrefab->GetName();

		int nMapIndex = m_mapDefinitionPrefabs.Find( pszPrefabName );

		// Make sure the item index is correct because we use this index as a reference
		SCHEMA_INIT_CHECK( 
			!m_mapDefinitionPrefabs.IsValidIndex( nMapIndex ),
			CFmtStr( "Duplicate prefab name (%s)", pszPrefabName ) );

		m_mapDefinitionPrefabs.Insert( pszPrefabName, pKVPrefab->MakeCopy() );
	}

	return SCHEMA_INIT_SUCCESS();
}