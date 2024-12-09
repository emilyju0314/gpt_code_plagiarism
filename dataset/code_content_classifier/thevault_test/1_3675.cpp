FOR_EACH_VEC( m_vecBundles, iBundle )
	{
		const CEconItemDefinition *pBundleItemDef = m_vecBundles[ iBundle ];
		if ( pBundleItemDef->IsPackBundle() )
			continue;

		// Go through all items in the bundle and look for pack items
		const bundleinfo_t *pBundle = pBundleItemDef->GetBundleInfo();
		if ( pBundle )
		{
			FOR_EACH_VEC( pBundle->vecItemEntries, iContainedBundleItem )
			{
				// Get the associated pack bundle
				const CEconItemDefinition *pContainedBundleItemDef = GetItemDefinition( pBundle->vecItemEntries[ iContainedBundleItem ].m_nItemDef );

				// Ignore non-pack items
				if ( !pContainedBundleItemDef || !pContainedBundleItemDef->IsPackItem() )
					continue;

				// Get the pack bundle that contains this particular pack item
				const CEconItemDefinition *pOwningPackBundleItemDef = pContainedBundleItemDef->GetOwningPackBundle();

				// Make sure all items in the owning pack bundle are in pBundleItemDef's bundle info (pBundle)
				const bundleinfo_t *pOwningPackBundle = pOwningPackBundleItemDef->GetBundleInfo();
				FOR_EACH_VEC( pOwningPackBundle->vecItemEntries, iCurPackBundleItem )
				{
					bool bFound = false;
					FOR_EACH_VEC( pBundle->vecItemEntries, i )
					{
						if ( pOwningPackBundle->vecItemEntries[ iCurPackBundleItem ].m_nItemDef == pBundle->vecItemEntries[ i ].m_nItemDef && 
							 pOwningPackBundle->vecItemEntries[ iCurPackBundleItem ].m_nPaintKit == pBundle->vecItemEntries[ i ].m_nPaintKit )
						{
							bFound = true;
							break;
						}
					}


					if ( !bFound )
					{
						SCHEMA_INIT_CHECK(
							false,
							CFmtStr( "The bundle \"%s\" contains some, but not all pack items required specified by pack bundle \"%s.\"",
							pBundleItemDef->GetDefinitionName(),
							pOwningPackBundleItemDef->GetDefinitionName()
							)
							);
					}
				}
			}
		}
	}