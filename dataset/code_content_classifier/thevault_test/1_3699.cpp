FOR_EACH_MAP_FAST( m_mapStickerKits, i )
	{
		CStickerKit * pStickerKit = m_mapStickerKits.Element( i );
		if ( !pStickerKit->m_nPlayerID ) continue;
		SCHEMA_INIT_CHECK(
			( m_mapProPlayersByAccountID.Find( pStickerKit->m_nPlayerID ) != m_mapProPlayersByAccountID.InvalidIndex() ),
			CFmtStr( "Pro-player sticker %d reference player %u which doesn't have a matching pro-player entry", pStickerKit->nID, pStickerKit->m_nPlayerID ) );
	}