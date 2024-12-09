bool CEconItemQualityDefinition::BInitFromKV( KeyValues *pKVQuality, CEconItemSchema &pschema, CUtlVector<CUtlString> *pVecErrors /* = NULL */ )
{

	m_nValue = pKVQuality->GetInt( "value", -1 );
	m_strName = pKVQuality->GetName();	
	m_bCanSupportSet = pKVQuality->GetBool( "canSupportSet" );
	m_strHexColor = pKVQuality->GetString( "hexColor" );
	m_unWeight = pKVQuality->GetInt( "weight", 0 );

	// Check for required fields
	SCHEMA_INIT_CHECK( 
		NULL != pKVQuality->FindKey( "value" ), 
		CFmtStr( "Quality definition %s: Missing required field \"value\"", pKVQuality->GetName() ) );

#if defined(CLIENT_DLL) || defined(GAME_DLL)
	return SCHEMA_INIT_SUCCESS();
#endif

	// Check for data consistency
	SCHEMA_INIT_CHECK( 
		0 != Q_stricmp( GetName(), "any" ), 
		CFmtStr( "Quality definition any: The quality name \"any\" is a reserved keyword and cannot be used." ) );

	SCHEMA_INIT_CHECK( 
		m_nValue != k_unItemQuality_Any, 
		CFmtStr( "Quality definition %s: Invalid value (%d). It is reserved for Any", GetName(), k_unItemQuality_Any ) );

	return SCHEMA_INIT_SUCCESS();
}