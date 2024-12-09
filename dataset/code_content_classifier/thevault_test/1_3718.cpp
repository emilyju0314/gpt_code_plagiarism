void CMaterialSystem::GenerateConfigFromConfigKeyValues( MaterialSystem_Config_t *pConfig, bool bOverwriteCommandLineValues )
{
	KeyValues *pKeyValues = new KeyValues( "config" );
	if ( !pKeyValues )
		return;

	if ( IsPC() && !GetRecommendedVideoConfig( pKeyValues ) ) 
	{
		pKeyValues->deleteThis();
		return;
	}

	float flAspectRatio;
	pConfig->m_Flags = 0;
	ReadInt( pKeyValues, "setting.defaultres", 640, -1, &pConfig->m_VideoMode.m_Width );
	ReadInt( pKeyValues, "setting.defaultresheight", 480, -1, &pConfig->m_VideoMode.m_Height );
	ReadFlt( pKeyValues, "setting.aspectratio", ( 4.0f / 3.0f ), -1, &flAspectRatio );
	
	int nUnsupported = 0;
	ReadInt( pKeyValues, "setting.unsupported", 0, -1, &nUnsupported );
	pConfig->SetFlag( MATSYS_VIDCFG_FLAGS_UNSUPPORTED, nUnsupported != 0 );

#ifdef LINUX

	uint width = 0;
	uint height = 0;
	uint refreshHz = 0; // Not used

	// query backbuffer size (window size whether FS or windowed)
	if( g_pLauncherMgr )
	{
		g_pLauncherMgr->GetNativeDisplayInfo( -1, width, height, refreshHz );
	}

	pConfig->m_VideoMode.m_Width = width;
	pConfig->m_VideoMode.m_Height = height;

#elif defined( _X360 )
	pConfig->m_VideoMode.m_Width = GetSystemMetrics( SM_CXSCREEN );
	pConfig->m_VideoMode.m_Height = GetSystemMetrics( SM_CYSCREEN );
	// We can afford better aniso in standard def
	if ( pConfig->m_VideoMode.m_Width == 640 )
	{
		static ConVarRef mat_forceaniso( "mat_forceaniso" );
		mat_forceaniso.SetValue( 8 );
	}
#elif defined( _PS3 )
	// Shader API does the dirty work of querying cellVideo libraries for screen res, so just piggy back on it
	ShaderDisplayMode_t info;
	g_pShaderDeviceMgr->GetModeInfo( &info, 0, 0 );
	pConfig->m_VideoMode.m_Width = info.m_nWidth;
	pConfig->m_VideoMode.m_Height = info.m_nHeight;
	// We can afford better aniso in standard def
	if ( pConfig->m_VideoMode.m_Width == 640 )
	{
		static ConVarRef mat_forceaniso( "mat_forceaniso" );
		mat_forceaniso.SetValue( 8 );
	}
#endif

	// Destroy the keys.
	pKeyValues->deleteThis();

	m_bGeneratedConfig = true;
}