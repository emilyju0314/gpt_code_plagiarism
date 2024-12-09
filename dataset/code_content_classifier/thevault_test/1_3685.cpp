bool CEconItemSchema::BInitAchievementRewards( KeyValues *pKVAchievementRewards, CUtlVector<CUtlString> *pVecErrors )
{
	m_dictAchievementRewards.Purge();
	m_mapAchievementRewardsByData.PurgeAndDeleteElements();

	// initialize the rewards sections
	if ( NULL != pKVAchievementRewards )
	{
		FOR_EACH_SUBKEY( pKVAchievementRewards, pKVReward )
		{
			AchievementAward_t award;
			if( pKVReward->GetDataType() == KeyValues::TYPE_NONE )
			{
				int32 nItemIndex = pKVReward->GetInt( "DefIndex", -1 );
				if( nItemIndex != -1 )
				{
					award.m_vecDefIndex.AddToTail( (uint16)nItemIndex );			
				}
				else
				{
					KeyValues *pkvItems = pKVReward->FindKey( "Items" );
					SCHEMA_INIT_CHECK( 
						pkvItems != NULL,
						CFmtStr( "Complex achievement %s must have an Items key or a DefIndex field", pKVReward->GetName() ) );
					if( !pkvItems )
					{
						continue;
					}

					FOR_EACH_VALUE( pkvItems, pkvItem )
					{
						award.m_vecDefIndex.AddToTail( (uint16)Q_atoi( pkvItem->GetName() ) );
					}
				}

			}
			else
			{
				award.m_vecDefIndex.AddToTail( (uint16)pKVReward->GetInt("", -1 ) );
			} 
		
			// make sure all the item types are valid
			bool bFoundAllItems = true;
			FOR_EACH_VEC( award.m_vecDefIndex, nItem )
			{
				const CEconItemDefinition *pDefn = GetItemDefinition( award.m_vecDefIndex[nItem] );
				SCHEMA_INIT_CHECK( 
					pDefn != NULL,
					CFmtStr( "Item definition index %d in achievement reward %s was not found", award.m_vecDefIndex[nItem], pKVReward->GetName() ) );
				if( !pDefn )
				{
					bFoundAllItems = false;
				}
			}
			if( !bFoundAllItems )
				continue;

			SCHEMA_INIT_CHECK( 
				award.m_vecDefIndex.Count() > 0,
				CFmtStr( "Achievement reward %s has no items!", pKVReward->GetName() ) );
			if( award.m_vecDefIndex.Count() == 0 )
				continue;

			award.m_unSourceAppId = k_uAppIdInvalid;
			if( pKVReward->GetDataType() == KeyValues::TYPE_NONE )
			{
				// cross game achievement
				award.m_sNativeName = pKVReward->GetName();
				award.m_unAuditData = pKVReward->GetInt( "AuditData", 0 );
				award.m_unSourceAppId = pKVReward->GetInt( "SourceAppID", award.m_unSourceAppId );
			}
			else
			{
				award.m_sNativeName = pKVReward->GetName();
				award.m_unAuditData = 0;
			}

			AchievementAward_t *pAward = new AchievementAward_t;
			*pAward = award;

			m_dictAchievementRewards.Insert( ComputeAchievementName( pAward->m_unSourceAppId, pAward->m_sNativeName ), pAward );
			m_mapAchievementRewardsByData.Insert( pAward->m_unAuditData, pAward );
		}
	}

	return SCHEMA_INIT_SUCCESS();
}