CEconCampaignDefinition::CEconCampaignNodeDefinition::CEconCampaignNodeStoryBlockDefinition * CEconCampaignDefinition::CEconCampaignNodeDefinition::GetBestScoringStoryBlock(  CEconItemView *pCampaignCoin  ) const
{
	CEconCampaignDefinition::CEconCampaignNodeDefinition::CEconCampaignNodeStoryBlockDefinition * pBestStoryBlock = NULL;
	float flBestStoryBlockScore = 0;

	
	FOR_EACH_VEC( GetStoryBlocks(), iSB )
	{
		float flCurStoryBlockScore = GetStoryBlocks()[ iSB ]->EvaluateStoryBlockExpression(  pCampaignCoin  );

		// only consider story block expressions that have a positive score
		if ( flCurStoryBlockScore > 0 )
		{
			if ( !pBestStoryBlock )
			{
				pBestStoryBlock = GetStoryBlocks()[ iSB ];
				flBestStoryBlockScore = flCurStoryBlockScore;
			}
			else
			{
				if ( flCurStoryBlockScore > flBestStoryBlockScore )
				{
					pBestStoryBlock = GetStoryBlocks()[ iSB ];
					flBestStoryBlockScore = flCurStoryBlockScore;
				}
			}
		}
	}

	return pBestStoryBlock;
}