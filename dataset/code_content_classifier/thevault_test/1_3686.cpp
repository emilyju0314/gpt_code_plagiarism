int CEconItemSchema::CalculateNumberOfConcreteItems( const CEconItemDefinition *pItemDef )
{
	AssertMsg( pItemDef, "NULL item definition!  This should not happen!" );
	if ( !pItemDef )
		return 0;

	if ( pItemDef->IsBundle() )
	{
		uint32 unNumConcreteItems = 0;
		
		const bundleinfo_t *pBundle = pItemDef->GetBundleInfo();
		Assert( pBundle );

		FOR_EACH_VEC( pBundle->vecItemEntries, i )
		{
			unNumConcreteItems += CalculateNumberOfConcreteItems(  GetItemDefinition( pBundle->vecItemEntries[i].m_nItemDef ) );
		}

		return unNumConcreteItems;
	}

	if ( pItemDef->GetItemClass() && !Q_strcmp( pItemDef->GetItemClass(), "map_token" ) )
		return 0;

	return 1;
}