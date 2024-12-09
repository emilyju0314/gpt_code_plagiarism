void CMaterialSystem::ReadConfigFromConVars( MaterialSystem_Config_t *pConfig )
{
	if ( !g_pCVar )
		return;

	// video panel config items
	pConfig->SetFlag( MATSYS_VIDCFG_FLAGS_NO_WAIT_FOR_VSYNC, !mat_vsync.GetBool() );
	pConfig->SetFlag( MATSYS_VIDCFG_FLAGS_DISABLE_SPECULAR, !mat_specular.GetBool() );
	pConfig->SetFlag( MATSYS_VIDCFG_FLAGS_DISABLE_BUMPMAP, !mat_bumpmap.GetBool() );
	pConfig->SetFlag( MATSYS_VIDCFG_FLAGS_DISABLE_DETAIL, !mat_detail_tex.GetBool() );
	pConfig->SetFlag( MATSYS_VIDCFG_FLAGS_DISABLE_PHONG, !mat_phong.GetBool() );
	pConfig->SetFlag( MATSYS_VIDCFG_FLAGS_ENABLE_PARALLAX_MAPPING, mat_parallaxmap.GetBool() );
	pConfig->m_nForceAnisotropicLevel = MAX( mat_forceaniso.GetInt(), 1 );

	// special handling for mat_dxlevel since it must be clamped to allowable values
	int nDxLevel = clamp( mat_dxlevel.GetInt(), g_pMaterialSystemHardwareConfig->GetMinDXSupportLevel(), g_pMaterialSystemHardwareConfig->GetMaxDXSupportLevel() );
	pConfig->dxSupportLevel = nDxLevel;
	mat_dxlevel.SetValue( nDxLevel );

	pConfig->skipMipLevels = mat_picmip.GetInt();

	pConfig->m_fMonitorGamma = mat_monitorgamma.GetFloat();
	pConfig->m_fGammaTVRangeMin = mat_monitorgamma_tv_range_min.GetFloat();
	pConfig->m_fGammaTVRangeMax = mat_monitorgamma_tv_range_max.GetFloat();
	pConfig->m_fGammaTVExponent = mat_monitorgamma_tv_exp.GetFloat();
	pConfig->m_bGammaTVEnabled = mat_monitorgamma_tv_enabled.GetBool();

	pConfig->m_bWantTripleBuffered = mat_triplebuffered.GetBool();
	pConfig->m_nAASamples = mat_antialias.GetInt();
	pConfig->m_nAAQuality = mat_aaquality.GetInt();
	pConfig->bShowDiffuse = mat_diffuse.GetBool();	
//	pConfig->bAllowCheats = false; // hack
	pConfig->bShowNormalMap = mat_normalmaps.GetBool();
	pConfig->bShowLowResImage = mat_showlowresimage.GetBool();
	pConfig->bMeasureFillRate = mat_measurefillrate.GetBool();
	pConfig->bVisualizeFillRate = mat_fillrate.GetBool();
	pConfig->bFilterLightmaps = mat_filterlightmaps.GetBool();
	pConfig->bFilterTextures = mat_filtertextures.GetBool();
	pConfig->bMipMapTextures = mat_mipmaptextures.GetBool();
	pConfig->nShowMipLevels = mat_showmiplevels.GetInt();
	pConfig->bReverseDepth = mat_reversedepth.GetBool();
	pConfig->bBufferPrimitives = mat_bufferprimitives.GetBool();
	pConfig->bDrawFlat = mat_drawflat.GetBool();
	pConfig->bSoftwareLighting = mat_softwarelighting.GetBool();
	pConfig->proxiesTestMode = mat_proxy.GetInt();
	pConfig->m_bSuppressRendering = mat_norendering.GetBool();
	pConfig->bCompressedTextures = mat_compressedtextures.GetBool();
	pConfig->bShowSpecular = mat_fastspecular.GetBool();
	pConfig->nFullbright = mat_fullbright.GetInt();
	pConfig->m_bFastNoBump = mat_fastnobump.GetBool();
	pConfig->m_bMotionBlur = mat_motion_blur_enabled.GetBool();
	pConfig->m_bSupportFlashlight = mat_supportflashlight.GetBool();
	pConfig->m_bShadowDepthTexture = r_flashlightdepthtexture.GetBool();
	pConfig->bDrawGray = mat_drawgray.GetBool();
	
	// PAINT
	pConfig->m_bPaintInGame = mat_paint_enabled.GetBool();
	pConfig->m_bPaintInMap = GetPaintmaps()->IsEnabled();

	ConVarRef csm_quality_level( "csm_quality_level" );
	pConfig->m_nCSMQuality = (CSMQualityMode_t)clamp( csm_quality_level.GetInt(), CSMQUALITY_VERY_LOW, (int)CSMQUALITY_TOTAL_MODES - 1 );

	pConfig->SetFlag( MATSYS_VIDCFG_FLAGS_ENABLE_HDR, HardwareConfig() && HardwareConfig()->GetHDREnabled() );
}