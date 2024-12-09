void CEconItemSchema::Reset( void )
{
	++m_unResetCount;

	m_unFirstValidClass = 0;
	m_unLastValidClass = 0;
	m_unFirstValidItemSlot = 0;
	m_unLastValidItemSlot = 0;
	m_unNumItemPresets = 0;
	m_unMinLevel = 0;
	m_unMaxLevel = 0;
	m_nMaxValidGraffitiTintDefID = 0;
	m_unSumQualityWeights = 0;
	m_mapRarities.Purge();
	m_mapSoundMaterials.Purge();
	m_mapQualities.Purge();
	m_mapItems.PurgeAndDeleteElements();
	m_mapItemsSorted.Purge();
	m_mapPaintKits.PurgeAndDeleteElements();
	m_mapStickerKits.PurgeAndDeleteElements();
	m_mapMusicDefs.PurgeAndDeleteElements();
	m_dictStickerKits.Purge();
	m_dictStickerLists.Purge();
	m_mapAttributesContainer.PurgeAndDeleteElements();
	FOR_EACH_VEC( m_vecAttributeTypes, i )
	{
		delete m_vecAttributeTypes[i].m_pAttrType;
	}
	m_vecAttributeTypes.Purge();
	m_mapRecipes.Purge();
	m_vecTimedRewards.Purge();
	m_mapAlternateIcons.Purge();
	m_mapItemSets.Purge();
	m_dictLootLists.Purge();
	m_mapAttributeControlledParticleSystems.Purge();
	m_unVersion = 0;
	if ( m_pKVRawDefinition )
	{
		m_pKVRawDefinition->deleteThis();
		m_pKVRawDefinition = NULL;
	}

#if defined(CLIENT_DLL) || defined(GAME_DLL)
	delete m_pDefaultItemDefinition;
	m_pDefaultItemDefinition = NULL;
#endif

	FOR_EACH_MAP_FAST( m_mapRecipes, i )
	{
		delete m_mapRecipes[i];
	}

	FOR_EACH_MAP_FAST( m_mapDefinitionPrefabs, i )
	{
		m_mapDefinitionPrefabs[i]->deleteThis();
	}
	m_mapDefinitionPrefabs.Purge();

	m_vecEquipRegionsList.Purge();
//	m_vecItemLevelingData.PurgeAndDeleteElements();
	m_vecItemLevelingData.Purge();

	m_RandomStream.SetSeed( 0 );
}