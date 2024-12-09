bool CTimedItemRewardDefinition::BInitFromKV( KeyValues *pKVTimedReward, CEconItemSchema &pschema, CUtlVector<CUtlString> *pVecErrors /* = NULL */ )
{
	// Parse the basic values
	m_flChance = pKVTimedReward->GetFloat( "pctChance" );
	
#ifdef DOTA_DLL
	m_unMinFreq = pKVTimedReward->GetInt( "value_min", 0 );
	m_unMaxFreq = pKVTimedReward->GetInt( "value_max", UINT_MAX );

	// Check required fields
	SCHEMA_INIT_CHECK( 
		NULL != pKVTimedReward->FindKey( "value_min" ), 
		CFmtStr( "Time reward %s: Missing required field \"value_min\"", pKVTimedReward->GetName() ) );
	SCHEMA_INIT_CHECK( 
		NULL != pKVTimedReward->FindKey( "value_max" ), 
		CFmtStr( "Time reward %s: Missing required field \"value_max\"", pKVTimedReward->GetName() ) );
#endif

	//
	// Parse the basic values
	//
	SCHEMA_INIT_CHECK( 
		NULL != pKVTimedReward->FindKey( "force_baseline_timestamp" ), 
		CFmtStr( "Time reward %s: Missing required field \"force_baseline_timestamp\"", pKVTimedReward->GetName() ) );
	m_rtForcedBaselineAdjustment = pKVTimedReward->GetInt( "force_baseline_timestamp" );

	m_rtForcedLastDropTimeAdjustment = 0;
	if ( pKVTimedReward->FindKey( "force_lastdrop_timestamp" ) )
		m_rtForcedLastDropTimeAdjustment = pKVTimedReward->GetInt( "force_lastdrop_timestamp" );
	
	m_unHoursInRewardPeriod = pKVTimedReward->GetInt( "period_hours", 0 );
	SCHEMA_INIT_CHECK( 
		NULL != pKVTimedReward->FindKey( "period_hours" ), 
		CFmtStr( "Time reward %s: Missing required field \"period_hours\"", pKVTimedReward->GetName() ) );
	SCHEMA_INIT_CHECK( 
		m_unHoursInRewardPeriod > 0, 
		CFmtStr( "Time reward %s: Required field \"period_hours\" has invalid value", pKVTimedReward->GetName() ) );

	m_unHoursBetweenDropsRealtime = pKVTimedReward->GetInt( "drop_interval_hours", 0 );
	SCHEMA_INIT_CHECK( 
		NULL != pKVTimedReward->FindKey( "drop_interval_hours" ), 
		CFmtStr( "Time reward %s: Missing required field \"drop_interval_hours\"", pKVTimedReward->GetName() ) );
	SCHEMA_INIT_CHECK( 
		m_unHoursBetweenDropsRealtime >= 0, 
		CFmtStr( "Time reward %s: Required field \"drop_interval_hours\" has invalid value", pKVTimedReward->GetName() ) );

	SCHEMA_INIT_CHECK( 
		NULL != pKVTimedReward->FindKey( "points_progression_hourly" ), 
		CFmtStr( "Time reward %s: Missing required field \"points_progression_hourly\"", pKVTimedReward->GetName() ) );
	uint32 numPointsAccumulatedValidation = 0;
	for ( KeyValues *kvPoints = pKVTimedReward->FindKey( "points_progression_hourly" )->GetFirstSubKey(); kvPoints; kvPoints = kvPoints->GetNextKey() )
	{
		uint32 numPoints = kvPoints->GetInt();
		SCHEMA_INIT_CHECK( 
			numPoints > numPointsAccumulatedValidation,
			CFmtStr( "Time reward %s: Required field \"points_progression_hourly\" defines invalid points after %u hours", pKVTimedReward->GetName(), m_arrTotalPointsBasedOnHoursPlayed.Count() ) );
		m_arrTotalPointsBasedOnHoursPlayed.AddToTail( numPoints );
		numPointsAccumulatedValidation = numPoints;
	}
	SCHEMA_INIT_CHECK( 
		NULL != pKVTimedReward->FindKey( "points_per_additional_hour" ), 
		CFmtStr( "Time reward %s: Missing required field \"points_per_additional_hour\"", pKVTimedReward->GetName() ) );
	m_unPointsPerHourOverplayed = pKVTimedReward->GetInt( "points_per_additional_hour", 0 );

	SCHEMA_INIT_CHECK( 
		NULL != pKVTimedReward->FindKey( "period_points_rollover" ), 
		CFmtStr( "Time reward %s: Missing required field \"period_points_rollover\"", pKVTimedReward->GetName() ) );
	m_unPointsPerPeriodRollover = pKVTimedReward->GetInt( "period_points_rollover", 0 );
	SCHEMA_INIT_CHECK( 
		m_unPointsPerPeriodRollover >= numPointsAccumulatedValidation,
		CFmtStr( "Time reward %s: Required field \"period_points_rollover\" defines invalid points after %u hours", pKVTimedReward->GetName(), m_arrTotalPointsBasedOnHoursPlayed.Count() ) );

	SCHEMA_INIT_CHECK( 
		NULL != pKVTimedReward->FindKey( "pctChance" ), 
		CFmtStr( "Time reward %s: Missing required field \"pctChance\"", pKVTimedReward->GetName() ) );
	
	SCHEMA_INIT_CHECK( 
		( m_flChance >= 0.0f ) && ( m_flChance <= 1.0f ),
		CFmtStr( "Time reward %s: Required field \"pctChance\" has invalid value", pKVTimedReward->GetName() ) );

	// Parse the criteria or loot_list
	if ( pKVTimedReward->FindKey( "criteria" ) )
	{
		bool bCriteriaOK = m_criteria.BInitFromKV( pKVTimedReward->FindKey( "criteria", true ), pschema );
		SCHEMA_INIT_CHECK( bCriteriaOK, CFmtStr( "Time Reward %s: Invalid criteria", pKVTimedReward->GetName() ) );

		// Check to make sure this criteria doesn't filter to an empty set
		if ( bCriteriaOK )
		{
			bool bMatch = false;
			FOR_EACH_MAP_FAST( pschema.GetItemDefinitionMap(), i )
			{
				if ( m_criteria.BEvaluate( pschema.GetItemDefinitionMap()[i], pschema ) )
				{
					bMatch = true;
					break;
				}
			}

			SCHEMA_INIT_CHECK(
				bMatch,
				CFmtStr( "Time Reward %s: No items match the critera", pKVTimedReward->GetName() ) );
		}
	}

	const char *pszLootList = pKVTimedReward->GetString("loot_list", NULL);
	if ( pszLootList && pszLootList[0] )
	{
		CUtlVector< char * > arrLootListsTokens;
		V_SplitString( pszLootList, ",", arrLootListsTokens );

		SCHEMA_INIT_CHECK( 
			arrLootListsTokens.Count() != 0,
			CFmtStr( "Time Reward %s: loot_list (%s) has zero elements", pKVTimedReward->GetName(), pszLootList ) );

		FOR_EACH_VEC( arrLootListsTokens, iLootListToken )
		{
			const CEconLootListDefinition *pLootList = pschema.GetLootListByName( arrLootListsTokens[iLootListToken] );

			// Make sure the item index is correct because we use this index as a reference
			SCHEMA_INIT_CHECK( 
				NULL != pLootList,
				CFmtStr( "Time Reward %s: loot_list (%s) element '%s' does not exist", pKVTimedReward->GetName(), pszLootList, arrLootListsTokens[iLootListToken] ) );

			if ( pLootList )
				m_arrLootLists.AddToTail( pLootList );
		}

		arrLootListsTokens.PurgeAndDeleteElements();
	}

	return SCHEMA_INIT_SUCCESS();
}