bool CEconItemSchema::BInitSoundMaterials( KeyValues *pKVSoundMaterials, CUtlVector<CUtlString> *pVecErrors )
{
	// initialize the item definitions
	if ( NULL != pKVSoundMaterials )
	{
		FOR_EACH_TRUE_SUBKEY( pKVSoundMaterials, pKVSoundMaterial )
		{
			int nSoundMaterialIndex = pKVSoundMaterial->GetInt( "value" );
			int nMapIndex = m_mapSoundMaterials.Find( nSoundMaterialIndex );

			// Make sure the item index is correct because we use this index as a reference
			SCHEMA_INIT_CHECK( 
				!m_mapSoundMaterials.IsValidIndex( nMapIndex ),
				CFmtStr( "Duplicate sound material value (%d)", nSoundMaterialIndex ) );

			nMapIndex = m_mapSoundMaterials.Insert( nSoundMaterialIndex );
			SCHEMA_INIT_SUBSTEP( m_mapSoundMaterials[nMapIndex].BInitFromKV( pKVSoundMaterial, *this, pVecErrors ) );
		}
	}

	return SCHEMA_INIT_SUCCESS();
}