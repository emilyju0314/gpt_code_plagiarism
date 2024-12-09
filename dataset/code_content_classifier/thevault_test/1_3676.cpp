bool CEconItemSchema::BInitItems( KeyValues *pKVItems, CUtlVector<CUtlString> *pVecErrors )
{
	FOR_EACH_TRUE_SUBKEY( pKVItems, pKVItem )
	{
		if ( Q_stricmp( pKVItem->GetName(), "default" ) == 0 )
		{
#if defined(CLIENT_DLL) || defined(GAME_DLL)
			SCHEMA_INIT_CHECK(
				m_pDefaultItemDefinition == NULL,
				CFmtStr( "Duplicate 'default' item definition." ) );

			if ( m_pDefaultItemDefinition == NULL )
			{
				m_pDefaultItemDefinition = CreateEconItemDefinition();
			}
			SCHEMA_INIT_SUBSTEP( m_pDefaultItemDefinition->BInitFromKV( pKVItem, *this, pVecErrors ) );
#endif
		}
		else
		{
			int nItemIndex = Q_atoi( pKVItem->GetName() );
			int nMapIndex = m_mapItems.Find( nItemIndex );

			// Make sure the item index is correct because we use this index as a reference
			SCHEMA_INIT_CHECK( 
				!m_mapItems.IsValidIndex( nMapIndex ),
				CFmtStr( "Duplicate item definition (%d)", nItemIndex ) );

			// Check to make sure the index is positive
			SCHEMA_INIT_CHECK( 
				nItemIndex >= 0,
				CFmtStr( "Item definition index %d must be greater than or equal to zero", nItemIndex ) );

			CEconItemDefinition *pItemDef = CreateEconItemDefinition();
			nMapIndex = m_mapItems.Insert( nItemIndex, pItemDef );
			m_mapItemsSorted.Insert( nItemIndex, pItemDef );
			SCHEMA_INIT_SUBSTEP( m_mapItems[nMapIndex]->BInitFromKV( pKVItem, *this, pVecErrors ) );
		}
	}

	return SCHEMA_INIT_SUCCESS();
}