bool CEconItemAttributeDefinition::BInitFromKV( KeyValues *pKVAttribute, CEconItemSchema &pschema, CUtlVector<CUtlString> *pVecErrors /* = NULL */ )
{
	m_pKVAttribute = pKVAttribute->MakeCopy();
	m_nDefIndex = Q_atoi( m_pKVAttribute->GetName() );
	
	m_pszDefinitionName = m_pKVAttribute->GetString("name");
	m_bHidden = m_pKVAttribute->GetInt( "hidden", 0 ) != 0;
	m_bWebSchemaOutputForced = m_pKVAttribute->GetInt( "force_output_description", 0 ) != 0;
	m_bStoredAsInteger = m_pKVAttribute->GetInt( "stored_as_integer", 0 ) != 0;
	m_iScore = m_pKVAttribute->GetInt( "score", 0 );
	m_iEffectType = (attrib_effect_types_t)StringFieldToInt( m_pKVAttribute->GetString("effect_type"), g_EffectTypes, ARRAYSIZE(g_EffectTypes) );
	m_iDescriptionFormat = StringFieldToInt( m_pKVAttribute->GetString("description_format"), g_AttributeDescriptionFormats, ARRAYSIZE(g_AttributeDescriptionFormats) );
	m_pszDescriptionString = m_pKVAttribute->GetString( "description_string", NULL );
	m_pszDescriptionTag = m_pKVAttribute->GetString( "description_tag", NULL );
	m_pszArmoryDesc = m_pKVAttribute->GetString( "armory_desc", NULL );
	m_pszAttributeClass = m_pKVAttribute->GetString( "attribute_class", NULL );
	m_bInstanceData = pKVAttribute->GetBool( "instance_data", false );

	const char *pszAttrType = m_pKVAttribute->GetString( "attribute_type", NULL );		// NULL implies "default type" for backwards compatibility
	m_pAttrType = pschema.GetAttributeType( pszAttrType );
	SCHEMA_INIT_CHECK(
		NULL != m_pAttrType,
		CFmtStr( "Attribute definition %s: Unable to find attribute data type '%s'", m_pszDefinitionName, pszAttrType ? pszAttrType : "(default)" ) );

#if defined(CLIENT_DLL) || defined(GAME_DLL)
	m_iszAttributeClass = NULL_STRING;
#endif

	// Check for required fields
	SCHEMA_INIT_CHECK( 
		NULL != m_pKVAttribute->FindKey( "name" ), 
		CFmtStr( "Attribute definition %s: Missing required field \"name\"", m_pKVAttribute->GetName() ) );

	m_unAssetClassBucket = pKVAttribute->GetInt( "asset_class_bucket", 0 );
	m_eAssetClassAttrExportRule = k_EAssetClassAttrExportRule_Default;
	if ( char const *szRule = pKVAttribute->GetString( "asset_class_export", NULL ) )
	{
		if ( !V_stricmp( szRule, "skip" ) )
		{
			m_eAssetClassAttrExportRule = k_EAssetClassAttrExportRule_Skip;
		}
		else if ( !V_stricmp( szRule, "gconly" ) )
		{
			m_eAssetClassAttrExportRule = EAssetClassAttrExportRule_t( k_EAssetClassAttrExportRule_GCOnly | k_EAssetClassAttrExportRule_Skip );
		}
		else if ( !V_stricmp( szRule, "bucketed" ) )
		{
			SCHEMA_INIT_CHECK(
				m_unAssetClassBucket,
				CFmtStr( "Attribute definition %s: Asset class export rule '%s' is incompatible", m_pszDefinitionName, szRule ) );
			m_eAssetClassAttrExportRule = k_EAssetClassAttrExportRule_Bucketed;
		}
		else if ( !V_stricmp( szRule, "default" ) )
		{
			m_eAssetClassAttrExportRule = k_EAssetClassAttrExportRule_Default;
		}
		else
		{
			SCHEMA_INIT_CHECK(
				false,
				CFmtStr( "Attribute definition %s: Invalid asset class export rule '%s'", m_pszDefinitionName, szRule ) );
		}
	}

	// Check for misuse of asset class bucket
	SCHEMA_INIT_CHECK(
		( !m_unAssetClassBucket || m_bInstanceData ),
		CFmtStr( "Attribute definition %s: Cannot use \"asset_class_bucket\" on class-level attributes", m_pKVAttribute->GetName() )
		);

	return SCHEMA_INIT_SUCCESS();
}