bool CEconItemSchema::BInitRarities( KeyValues *pKVRarities, CUtlVector<CUtlString> *pVecErrors )
{
	// initialize the item definitions
	if ( NULL != pKVRarities )
	{
		FOR_EACH_TRUE_SUBKEY( pKVRarities, pKVRarity )
		{
			int nRarityIndex = pKVRarity->GetInt( "value" );
			int nMapIndex = m_mapRarities.Find( nRarityIndex );

			// Make sure the item index is correct because we use this index as a reference
			SCHEMA_INIT_CHECK( 
				!m_mapRarities.IsValidIndex( nMapIndex ),
				CFmtStr( "Duplicate rarity value (%d)", nRarityIndex ) );

			nMapIndex = m_mapRarities.Insert( nRarityIndex );
			SCHEMA_INIT_SUBSTEP( m_mapRarities[nMapIndex].BInitFromKV( pKVRarity, *this, pVecErrors ) );
		}
	}

	return SCHEMA_INIT_SUCCESS();
}