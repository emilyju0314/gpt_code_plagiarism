bool CEconItemSchema::BInitKillEaterScoreTypes( KeyValues *pKVKillEaterScoreTypes, CUtlVector<CUtlString> *pVecErrors )
{
	m_mapKillEaterScoreTypes.RemoveAll();

	// initialize the rewards sections
	if ( NULL != pKVKillEaterScoreTypes )
	{
		FOR_EACH_TRUE_SUBKEY( pKVKillEaterScoreTypes, pKVScoreType )
		{
			unsigned int unIndex = (unsigned int)atoi( pKVScoreType->GetName() );
			SCHEMA_INIT_CHECK( m_mapKillEaterScoreTypes.Find( unIndex ) == KillEaterScoreMap_t::InvalidIndex(),
				CFmtStr( "Duplicate kill eater score type index %u.", unIndex ) );
			
			kill_eater_score_type_t ScoreType;
			ScoreType.m_nValue = V_atoi( pKVScoreType->GetName() );
			ScoreType.m_pszTypeString = pKVScoreType->GetString( "type_name" );
			ScoreType.m_pszModelAttributeString = pKVScoreType->GetString( "model_attribute" );
#ifdef CLIENT_DLL
			HelperValidateLocalizationStringToken( CFmtStr( "#KillEaterDescriptionNotice_%s", ScoreType.m_pszTypeString ) );
			HelperValidateLocalizationStringToken( CFmtStr( "#KillEaterEventType_%s", ScoreType.m_pszTypeString ) );
#endif

			// Default to on.
			ScoreType.m_bUseLevelBlock = pKVScoreType->GetBool( "use_level_data", 1 );

			const char *pszLevelBlockName = pKVScoreType->GetString( "level_data", "KillEaterRank" );
			SCHEMA_INIT_CHECK( GetItemLevelingData( pszLevelBlockName ) != NULL,
				CFmtStr( "Unable to find leveling data block named \"%s\" for kill eater score type %u.", pszLevelBlockName, unIndex ) );

			ScoreType.m_pszLevelBlockName = pszLevelBlockName;

			m_mapKillEaterScoreTypes.Insert( unIndex, ScoreType );
		}
	}

	return SCHEMA_INIT_SUCCESS();
}