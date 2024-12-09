FOR_EACH_MAP_FAST( GetStartNodes(), i )
		{
			uint32 nCampaignNodeIndex = GetStartNodes().Key( i );

			// is this start quest already complete?
			if ( ( 1 << ( nCampaignNodeIndex - 1 ) ) & unCampaignCompletionBitfield )
			{
				// yes. recurse.
				Helper_RecursiveGetAccessibleCampaignNodes( unCampaignCompletionBitfield, GetStartNodes().Element( i ), vecAccessibleNodes );
			}
			else
			{
				// no. add it to the list and return;
				vecAccessibleNodes.AddToTail( GetStartNodes().Element( i ) );
			}
		}