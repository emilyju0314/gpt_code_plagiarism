bool CEconItemSchema::BInitQualities( KeyValues *pKVQualities, CUtlVector<CUtlString> *pVecErrors )
{
	// initialize the item definitions
	if ( NULL != pKVQualities )
	{
		FOR_EACH_TRUE_SUBKEY( pKVQualities, pKVQuality )
		{
			int nQualityIndex = pKVQuality->GetInt( "value" );
			int nMapIndex = m_mapQualities.Find( nQualityIndex );

			// Make sure the item index is correct because we use this index as a reference
			SCHEMA_INIT_CHECK( 
				!m_mapQualities.IsValidIndex( nMapIndex ),
				CFmtStr( "Duplicate quality value (%d)", nQualityIndex ) );

			nMapIndex = m_mapQualities.Insert( nQualityIndex );
			SCHEMA_INIT_SUBSTEP( m_mapQualities[nMapIndex].BInitFromKV( pKVQuality, *this, pVecErrors ) );
		}
	}

	// Check the integrity of the quality definitions

	// Check for duplicate quality names
	CUtlRBTree<const char *> rbQualityNames( CaselessStringLessThan );
	rbQualityNames.EnsureCapacity( m_mapQualities.Count() );
	FOR_EACH_MAP_FAST( m_mapQualities, i )
	{
		int iIndex = rbQualityNames.Find( m_mapQualities[i].GetName() );
		SCHEMA_INIT_CHECK( 
			!rbQualityNames.IsValidIndex( iIndex ),
			CFmtStr( "Quality definition %d: Duplicate quality name %s", m_mapQualities[i].GetDBValue(), m_mapQualities[i].GetName() ) );

		if( !rbQualityNames.IsValidIndex( iIndex ) )
			rbQualityNames.Insert( m_mapQualities[i].GetName() );
	}

	return SCHEMA_INIT_SUCCESS();
}