FOR_EACH_SUBKEY( pKVExpressionTokens, kvSubKey )
	{
		uint16 unQuestID = V_atoi( kvSubKey->GetName() );

		uint32 unCampaignID;
		uint32 unCampaignNodeID;

		ResolveQuestIdToCampaignAndIndex( unQuestID, unCampaignID, unCampaignNodeID );

		const CSchemaAttributeDefHandle pAttr_CampaignCompletionBitfield = GetCampaignAttributeDefHandle( unCampaignID, k_ECampaignAttribute_CompletionBitfield );
		
		uint32 unCampaignCompletionBitfield;
		if ( !pCampaignCoin->FindAttribute( pAttr_CampaignCompletionBitfield, &unCampaignCompletionBitfield ) )
			return 0;

		uint32 unMask = ( 1 << ( unCampaignNodeID - 1 ) );

		const char * szKeyWord = CFmtStr( "%%%s%%", kvSubKey->GetName() );
		float flCompletionState = ( unCampaignCompletionBitfield & unMask ) ? 1.0 : 0.0;
		expStoryBlock.SetVariable( szKeyWord, flCompletionState );
	}