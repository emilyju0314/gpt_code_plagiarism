FOR_EACH_MAP_FAST( m_mapCampaignNodes, i )
	{
		const CUtlVector< uint32 >& pNextNodes = m_mapCampaignNodes.Element( i )->GetNextNodes();

		FOR_EACH_VEC( pNextNodes, j )
		{
			int nextnode = pNextNodes[ j ];

			int index = m_mapCampaignNodes.Find( nextnode );

			SCHEMA_INIT_CHECK( 
				m_mapCampaignNodes.IsValidIndex( index ),
				CFmtStr( "Campaign definition %d: campaign node index %d leads to an invalid campaign node %d", GetID(), m_mapCampaignNodes.Element( i )->GetID(), nextnode ) );
		
		}

	}