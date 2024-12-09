bool CEconItemDefinition::BInitAlternateIconsFromKV( KeyValues *pKVAlternateIcons, CEconItemSchema &pschema, AssetInfo *pVisData, CUtlVector<CUtlString> *pVecErrors )
{
	m_pMapAlternateIcons->Purge();

	FOR_EACH_TRUE_SUBKEY( pKVAlternateIcons, pKVAlternateIcon )
	{
		int iIconIndex = Q_atoi( pKVAlternateIcon->GetName() );

		SCHEMA_INIT_CHECK( 
			!m_pMapAlternateIcons->Find( iIconIndex ) != m_pMapAlternateIcons->InvalidIndex(),
			CFmtStr( "Duplicate alternate icon definition (%d)", iIconIndex ) );

		SCHEMA_INIT_CHECK( 
			iIconIndex >= 0,
			CFmtStr( "Alternate icon definition index %d must be greater than or equal to zero", iIconIndex ) );

		m_pMapAlternateIcons->Insert( iIconIndex, pKVAlternateIcon->GetString( "icon_path" ) );
	}

	return SCHEMA_INIT_SUCCESS();
}