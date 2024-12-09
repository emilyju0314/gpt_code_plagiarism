bool CEconItemDefinition::BInitFromTestItemKVs( int iNewDefIndex, KeyValues *pKVItem, CEconItemSchema &pschema )
{
	// The KeyValues are stored in the player entity, so we can cache our name there

	m_nDefIndex = iNewDefIndex;

	bool bTestingExistingItem = pKVItem->GetInt( "test_existing_item", 0 ) != 0;
	if ( !bTestingExistingItem )
	{
		m_pszDefinitionName = pKVItem->GetString( "name", NULL );
		m_pszItemBaseName = pKVItem->GetString( "name", NULL );

#ifdef CLIENT_DLL
		pKVItem->SetString( "name", VarArgs("Test Item %d", iNewDefIndex) );
#else
		pKVItem->SetString( "name", UTIL_VarArgs("Test Item %d", iNewDefIndex) );
#endif

		m_pszBaseDisplayModel = pKVItem->GetString( "model_player", NULL );
		m_bAttachToHands = pKVItem->GetInt( "attach_to_hands", 0 ) != 0;

		BInitVisualBlockFromKV( pKVItem, pschema );

		m_pszParticleFile = pKVItem->GetString( "particle_file", NULL );
		m_pszParticleSnapshotFile = pKVItem->GetString( "particle_snapshot", NULL );
	}

	// Handle attributes
	PurgeStaticAttributes();

	int iPaintCanIndex = pKVItem->GetInt("paintcan_index", 0);
	if ( iPaintCanIndex )
	{
		static CSchemaAttributeDefHandle pAttrDef_PaintRGB( "set item tint RGB" );

		const CEconItemDefinition *pCanDef = pschema.GetItemDefinition(iPaintCanIndex);

		float flRGBVal;
		if ( pCanDef && pAttrDef_PaintRGB && FindAttribute_UnsafeBitwiseCast<attrib_value_t>( pCanDef, pAttrDef_PaintRGB, &flRGBVal ) )
		{
			static_attrib_t& StaticAttrib = m_vecStaticAttributes[ m_vecStaticAttributes.AddToTail() ];

			StaticAttrib.iDefIndex = pAttrDef_PaintRGB->GetDefinitionIndex();
			StaticAttrib.m_value.asFloat = flRGBVal;							// this is bad! but we're in crazy hack code for UI customization of item definitions that don't exist so
		}
	}

	return true;
}