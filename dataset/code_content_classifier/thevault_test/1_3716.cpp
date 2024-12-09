void CMaterialSystem::ReleaseShaderObjects( int nChangeFlags )
{	
	if( mat_debugalttab.GetBool() )
	{
		Warning( "mat_debugalttab: CMaterialSystem::ReleaseShaderObjects\n" );
	}

	Flush( false );

	m_HardwareRenderContext.OnReleaseShaderObjects();

	if ( ( nChangeFlags & MATERIAL_RESTORE_VERTEX_FORMAT_CHANGED ) == 0 ) 
	{
		g_pOcclusionQueryMgr->FreeOcclusionQueryObjects();

		// If we're in an alt+tab event don't release managed resources
		bool bReleaseManaged = ( nChangeFlags & MATERIAL_RESTORE_RELEASE_MANAGED_RESOURCES ) ? true : false;
		m_bRestoreManangedResources = bReleaseManaged;

		TextureManager()->ReleaseTextures( bReleaseManaged );
		ReleaseStandardTextures();
		if ( bReleaseManaged )
		{
			GetLightmaps()->ReleaseLightmapPages();
		}
	}
	for (int i = 0; i < m_ReleaseFunc.Count(); ++i)
	{
		m_ReleaseFunc[i]( nChangeFlags );
	}
}