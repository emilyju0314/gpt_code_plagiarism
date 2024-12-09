void CEconItemSchema::ItemTesting_CreateTestDefinition( int iCloneFromItemDef, int iNewDef, KeyValues *pNewKV )
{
	int nMapIndex = m_mapItems.Find( iNewDef );
	if ( !m_mapItems.IsValidIndex( nMapIndex ) )
	{
		nMapIndex = m_mapItems.Insert( iNewDef, CreateEconItemDefinition() );
		m_mapItemsSorted.Insert( iNewDef, m_mapItems[nMapIndex] );
	}

	// Find & copy the clone item def's data in
	const CEconItemDefinition *pCloneDef = GetItemDefinition( iCloneFromItemDef );
	if ( !pCloneDef )
		return;
	m_mapItems[nMapIndex]->CopyPolymorphic( pCloneDef );

	// Then stomp it with the KV test contents
	m_mapItems[nMapIndex]->BInitFromTestItemKVs( iNewDef, pNewKV, *this );
}