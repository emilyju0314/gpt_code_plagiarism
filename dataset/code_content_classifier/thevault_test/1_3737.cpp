void CMatLightmaps::BeginLightmapAllocation()
{
	// we clean up lightmaps on console right before we load the next map
	if ( IsPC() )
	{
		CleanupLightmaps();
	}

	m_ImagePackers.RemoveAll();
	int i = m_ImagePackers.AddToTail();
	m_ImagePackers[i].Reset( 0, GetMaxLightmapPageWidth(), GetMaxLightmapPageHeight() );

	SetCurrentMaterialInternal(0);
	m_currentWhiteLightmapMaterial = 0;
	m_numSortIDs = 0;

	// need to set the min and max sorting id number for each material to 
	// a default value that basically means that it hasn't been used yet.
	ResetMaterialLightmapPageInfo();

	EnumerateMaterials();
}