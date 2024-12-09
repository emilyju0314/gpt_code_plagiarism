FOR_EACH_MAP_FAST( m_mapItems, i )
	{
		CEconItemDefinition *pItemDef = m_mapItems[ i ];
		if ( !pItemDef )
			continue;

		KeyValues* pItemKV = pItemDef->GetRawDefinition();
		if ( !pItemKV )
			continue;

		KeyValues *pBundleDataKV = pItemKV->FindKey( "bundle" );
		if ( pBundleDataKV )
		{
			pItemDef->m_BundleInfo = new bundleinfo_t();
			FOR_EACH_SUBKEY( pBundleDataKV, pKVCurItem )
			{
				item_list_entry_t entry;
				bool bEntrySuccess = entry.InitFromName( pKVCurItem->GetName() );

				SCHEMA_INIT_CHECK( 
					bEntrySuccess,
					CFmtStr( "Bundle %s: Item definition \"%s\" failed to initialize\n", pItemDef->m_pszDefinitionName, pKVCurItem->GetName() ) );

				const CEconItemDefinition *pBundleItemDef = GetItemDefinition( entry.m_nItemDef );
				SCHEMA_INIT_CHECK( pBundleItemDef, CFmtStr( "Unable to find item definition '%s' for bundle '%s'.", pKVCurItem->GetName(), pItemDef->m_pszDefinitionName ) );

				pItemDef->m_BundleInfo->vecItemEntries.AddToTail( entry );
			}

			// Only check for pack bundle if the item is actually a bundle - note that we could do this programatically by checking that all items in the bundle are flagged as a "pack item" - but for now the bundle needs to be explicitly flagged as a pack bundle.
			pItemDef->m_bIsPackBundle = pItemKV->GetInt( "is_pack_bundle", 0 ) != 0;
		}

		// Make a list of all of our bundles.
		if ( pItemDef->IsBundle() )
		{
			// Cache off the item def for the bundle, since we'll need both the bundle info and the item def index later.
			m_vecBundles.AddToTail( pItemDef );

			// If the bundle is a pack bundle, mark all the contained items as pack items / link to the owning pack bundle
			if ( pItemDef->IsPackBundle() )
			{
				const bundleinfo_t *pBundleInfo = pItemDef->GetBundleInfo();
				FOR_EACH_VEC( pBundleInfo->vecItemEntries, iCurItem )
				{
					CEconItemDefinition *pCurItemDef = GetItemDefinitionMutable( pBundleInfo->vecItemEntries[ iCurItem ].m_nItemDef );
					SCHEMA_INIT_CHECK( NULL == pCurItemDef->m_pOwningPackBundle, CFmtStr( "Pack item \"%s\" included in more than one pack bundle - not allowed!", pCurItemDef->GetDefinitionName() ) );
					pCurItemDef->m_pOwningPackBundle = pItemDef;
				}
			}
		}
	}