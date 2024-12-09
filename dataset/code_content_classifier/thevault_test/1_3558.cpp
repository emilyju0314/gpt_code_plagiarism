void CShaderAPIDx8::SetPIXMarker( unsigned long color, const char* szName )
{
#if !defined( POSIX )
#if defined( PIX_INSTRUMENTATION )
	LOCK_SHADERAPI();

	#if defined( DX_TO_GL_ABSTRACTION )
		if ( g_pShaderDeviceMgrDx8->m_pSetMarker )
		{
			wchar_t wszName[128];
			mbstowcs(wszName, szName, 128 );
			g_pShaderDeviceMgrDx8->m_pSetMarker( 0x2F2F2F2F, wszName );
		}
	#elif defined( _X360 )
		#ifndef _DEBUG
			char szPIXMarkerName[32];
			PIXifyName( szPIXMarkerName, szName );
			PIXSetMarker( color, szPIXMarkerName );
		#endif
	#else // PC
		if ( PIXError() )
			return;
		wchar_t wszName[128];
		mbstowcs(wszName, szName, 128 );
		D3DPERF_SetMarker( color, wszName );
	#endif

#endif  // PIX_INSTRUMENTATION
#endif // not POSIX
}