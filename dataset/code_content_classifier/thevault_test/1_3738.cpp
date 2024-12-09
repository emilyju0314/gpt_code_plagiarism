int CMatLightmaps::AllocateLightmap( int width, int height, 
		                               int offsetIntoLightmapPage[2],
									   IMaterial *iMaterial )
{
	IMaterialInternal *pMaterial = static_cast<IMaterialInternal *>( iMaterial );
	if ( !pMaterial )
	{
		Warning( "Programming error: CMatRenderContext::AllocateLightmap: NULL material\n" );
		return m_numSortIDs;
	}
	pMaterial = pMaterial->GetRealTimeVersion(); //always work with the real time versions of materials internally
	
	// material change
	int i;
	int nPackCount = m_ImagePackers.Count();
	if ( GetCurrentMaterialInternal() != pMaterial )
	{
		// If this happens, then we need to close out all image packers other than
		// the last one so as to produce as few sort IDs as possible
		for ( i = nPackCount - 1; --i >= 0; )
		{
			// NOTE: We *must* use the order preserving one here so the remaining one
			// is the last lightmap
			m_ImagePackers.Remove( i );
			--nPackCount;
		}

		// If it's not the first material, increment the sort id
		if (GetCurrentMaterialInternal())
		{
			m_ImagePackers[0].IncrementSortId( );
			++m_numSortIDs;
		}

		SetCurrentMaterialInternal(pMaterial);

		// This assertion guarantees we don't see the same material twice in this loop.
		Assert( pMaterial->GetMinLightmapPageID( ) > pMaterial->GetMaxLightmapPageID() );

		// NOTE: We may not use this lightmap page, but we might
		// we won't know for sure until the next material is passed in.
		// So, for now, we're going to forcibly add the current lightmap
		// page to this material so the sort IDs work out correctly.
		GetCurrentMaterialInternal()->SetMinLightmapPageID( GetNumLightmapPages() );
		GetCurrentMaterialInternal()->SetMaxLightmapPageID( GetNumLightmapPages() );
	}

	// Try to add it to any of the current images...
	bool bAdded = false;
	for ( i = 0; i < nPackCount; ++i )
	{
		bAdded = m_ImagePackers[i].AddBlock( width, height, &offsetIntoLightmapPage[0], &offsetIntoLightmapPage[1] );
		if ( bAdded )
			break;
	}

	if ( !bAdded )
	{
		++m_numSortIDs;
		i = m_ImagePackers.AddToTail();
		m_ImagePackers[i].Reset( m_numSortIDs, GetMaxLightmapPageWidth(), GetMaxLightmapPageHeight() );
		++m_NumLightmapPages;
		if ( !m_ImagePackers[i].AddBlock( width, height, &offsetIntoLightmapPage[0], &offsetIntoLightmapPage[1] ) )
		{
			Error( "MaterialSystem_Interface_t::AllocateLightmap: lightmap (%dx%d) too big to fit in page (%dx%d)\n", 
				width, height, GetMaxLightmapPageWidth(), GetMaxLightmapPageHeight() );
		}

		// Add this lightmap to the material...
		GetCurrentMaterialInternal()->SetMaxLightmapPageID( GetNumLightmapPages() );
	}

	return m_ImagePackers[i].GetSortId();
}