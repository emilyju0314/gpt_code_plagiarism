void CMaterialSystem::WriteConfigIntoConVars( const MaterialSystem_Config_t &config )
{
	if ( !g_pCVar )
		return;

	mat_vsync.SetValue( config.WaitForVSync() );
	mat_specular.SetValue( config.UseSpecular() );
	mat_bumpmap.SetValue( config.UseBumpmapping() );
	mat_detail_tex.SetValue( config.UseDetailTexturing() );
	mat_parallaxmap.SetValue( config.UseParallaxMapping() );
	mat_forceaniso.SetValue( config.m_nForceAnisotropicLevel );
	mat_dxlevel.SetValue( config.dxSupportLevel );
	mat_picmip.SetValue( config.skipMipLevels );
	mat_phong.SetValue( config.UsePhong() );

	mat_monitorgamma.SetValue( config.m_fMonitorGamma );
	mat_monitorgamma_tv_range_min.SetValue( config.m_fGammaTVRangeMin );
	mat_monitorgamma_tv_range_max.SetValue( config.m_fGammaTVRangeMax );
	mat_monitorgamma_tv_exp.SetValue( config.m_fGammaTVExponent );
	mat_monitorgamma_tv_enabled.SetValue( config.m_bGammaTVEnabled );

	mat_triplebuffered.SetValue( config.m_bWantTripleBuffered ? 1 : 0 );
	mat_antialias.SetValue( config.m_nAASamples );
	mat_aaquality.SetValue( config.m_nAAQuality );
	mat_diffuse.SetValue( config.bShowDiffuse ? 1 : 0 );	
//	config.bAllowCheats = false; // hack
	mat_normalmaps.SetValue( config.bShowNormalMap ? 1 : 0 );
	mat_showlowresimage.SetValue( config.bShowLowResImage ? 1 : 0 );
	mat_measurefillrate.SetValue( config.bMeasureFillRate ? 1 : 0 );
	mat_fillrate.SetValue( config.bVisualizeFillRate ? 1 : 0 );
	mat_filterlightmaps.SetValue( config.bFilterLightmaps ? 1 : 0 );
	mat_filtertextures.SetValue( config.bFilterTextures ? 1 : 0 );
	mat_mipmaptextures.SetValue( config.bMipMapTextures ? 1 : 0 );
	mat_showmiplevels.SetValue( config.nShowMipLevels );
	mat_reversedepth.SetValue( config.bReverseDepth ? 1 : 0 );
	mat_bufferprimitives.SetValue( config.bBufferPrimitives ? 1 : 0 );
	mat_drawflat.SetValue( config.bDrawFlat ? 1 : 0 );
	mat_softwarelighting.SetValue( config.bSoftwareLighting ? 1 : 0 );
	mat_proxy.SetValue( config.proxiesTestMode );
	mat_norendering.SetValue( config.m_bSuppressRendering ? 1 : 0 );
	mat_compressedtextures.SetValue( config.bCompressedTextures ? 1 : 0 );
	mat_fastspecular.SetValue( config.bShowSpecular ? 1 : 0 );
	mat_fullbright.SetValue( config.nFullbright );
	mat_fastnobump.SetValue( config.m_bFastNoBump ? 1 : 0 );
	bool hdre = config.HDREnabled();
	HardwareConfig()->SetHDREnabled( hdre );
	r_flashlightdepthtexture.SetValue( config.m_bShadowDepthTexture ? 1 : 0 );
	mat_motion_blur_enabled.SetValue( config.m_bMotionBlur ? 1 : 0 );
	mat_supportflashlight.SetValue( config.m_bSupportFlashlight ? 1 : 0 );
	mat_drawgray.SetValue( config.bDrawGray ? 1 : 0 );

	ConVarRef csm_quality_level( "csm_quality_level" );
	csm_quality_level.SetValue( clamp<int>( config.m_nCSMQuality, CSMQUALITY_VERY_LOW, CSMQUALITY_TOTAL_MODES - 1 ) );
}