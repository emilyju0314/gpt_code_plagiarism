bool CEconItemSchema::BInitGameInfo( KeyValues *pKVGameInfo, CUtlVector<CUtlString> *pVecErrors )
{
	m_unFirstValidClass = pKVGameInfo->GetInt( "first_valid_class", 0 );
	m_unLastValidClass = pKVGameInfo->GetInt( "last_valid_class", 0 );
	SCHEMA_INIT_CHECK( 0 <= m_unFirstValidClass, CFmtStr( "First valid class must be greater or equal to 0." ) );
	SCHEMA_INIT_CHECK( m_unFirstValidClass <= m_unLastValidClass, CFmtStr( "First valid class must be less than or equal to last valid class." ) );

	m_unFirstValidItemSlot = pKVGameInfo->GetInt( "first_valid_item_slot", INVALID_EQUIPPED_SLOT );
	m_unLastValidItemSlot = pKVGameInfo->GetInt( "last_valid_item_slot", INVALID_EQUIPPED_SLOT );
	SCHEMA_INIT_CHECK( INVALID_EQUIPPED_SLOT != m_unFirstValidItemSlot, CFmtStr( "first_valid_item_slot not set!" ) );
	SCHEMA_INIT_CHECK( INVALID_EQUIPPED_SLOT != m_unLastValidItemSlot, CFmtStr( "last_valid_item_slot not set!" ) );
	SCHEMA_INIT_CHECK( m_unFirstValidItemSlot <= m_unLastValidItemSlot, CFmtStr( "First valid item slot must be less than or equal to last valid item slot." ) );

	m_unNumItemPresets = pKVGameInfo->GetInt( "num_item_presets", -1 );
	SCHEMA_INIT_CHECK( (uint32)-1 != m_unNumItemPresets, CFmtStr( "num_item_presets not set!" ) );

	return SCHEMA_INIT_SUCCESS();
}