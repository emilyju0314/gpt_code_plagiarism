FOR_EACH_MAP_FAST( m_mapCampaignDefs, iC )
	{
		FOR_EACH_MAP_FAST( m_mapCampaignDefs.Element( iC )->GetCampaignNodes(), iCn )
		{
			CEconCampaignDefinition::CEconCampaignNodeDefinition * pCNodeDef = m_mapCampaignDefs.Element( iC )->GetCampaignNodes().Element( iCn );

			FOR_EACH_VEC( pCNodeDef->GetStoryBlocks(), iSB )
			{

				KeyValues * pKVExpressionTokens = new KeyValues( "ExpressionTokens" );
				KeyValues::AutoDelete autodelete( pKVExpressionTokens );

				CEconQuestDefinition::TokenizeQuestExpression( pCNodeDef->GetStoryBlocks()[ iSB ]->GetStoryBlockExpression(), pKVExpressionTokens );

				FOR_EACH_SUBKEY( pKVExpressionTokens, kvSubKey )
				{
					int iQ = m_mapQuestDefs.Find( V_atoi( kvSubKey->GetName() ) );

					SCHEMA_INIT_CHECK(
						( m_mapQuestDefs.IsValidIndex( iQ ) ),
						CFmtStr( "campaign %d, node %d, Story_block %d, references a non-existant quest index %d.", iC, iCn, iSB, iQ ) );

				}
			}
		}
	}