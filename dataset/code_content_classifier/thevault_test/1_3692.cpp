bool CEconItemSchema::BInitArmoryData( KeyValues *pKVArmoryData, CUtlVector<CUtlString> *pVecErrors )
{
	m_dictArmoryItemDataStrings.Purge();
	m_dictArmoryAttributeDataStrings.Purge();
	if ( NULL != pKVArmoryData )
	{
		KeyValues *pKVItemTypes = pKVArmoryData->FindKey( "armory_item_types" );
		if ( pKVItemTypes )
		{
			FOR_EACH_SUBKEY( pKVItemTypes, pKVEntry )
			{
				const char *pszDataKey = pKVEntry->GetName();
				const char *pszLocString = pKVEntry->GetString();
				m_dictArmoryItemTypesDataStrings.Insert( pszDataKey, pszLocString );
			}
		}

		pKVItemTypes = pKVArmoryData->FindKey( "armory_item_classes" );
		if ( pKVItemTypes )
		{
			FOR_EACH_SUBKEY( pKVItemTypes, pKVEntry )
			{
				const char *pszDataKey = pKVEntry->GetName();
				const char *pszLocString = pKVEntry->GetString();
				m_dictArmoryItemClassesDataStrings.Insert( pszDataKey, pszLocString );
			}
		}

		KeyValues *pKVAttribs = pKVArmoryData->FindKey( "armory_attributes" );
		if ( pKVAttribs )
		{
			FOR_EACH_SUBKEY( pKVAttribs, pKVEntry )
			{
				const char *pszDataKey = pKVEntry->GetName();
				const char *pszLocString = pKVEntry->GetString();
				m_dictArmoryAttributeDataStrings.Insert( pszDataKey, pszLocString );
			}
		}

		KeyValues *pKVItems = pKVArmoryData->FindKey( "armory_items" );
		if ( pKVItems )
		{
			FOR_EACH_SUBKEY( pKVItems, pKVEntry )
			{
				const char *pszDataKey = pKVEntry->GetName();
				const char *pszLocString = pKVEntry->GetString();
				m_dictArmoryItemDataStrings.Insert( pszDataKey, pszLocString );
			}
		}
	}
	return SCHEMA_INIT_SUCCESS();
}