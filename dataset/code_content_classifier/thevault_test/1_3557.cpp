void CShaderAPIDx8::BeginPIXEvent( unsigned long color, const char* szName )
{
#if ( defined( PIX_INSTRUMENTATION ) || defined( NVPERFHUD ) )
	LOCK_SHADERAPI();

	const char *p = pix_break_on_event.GetString();
	if ( p && V_strlen( p ) )
	{
		if ( V_stristr( szName, p ) != NULL )
		{
			DebuggerBreak();
		}
	}

	#if defined ( DX_TO_GL_ABSTRACTION )
		GLMBeginPIXEvent( szName );

		#if defined( _WIN32 )
			// AMD PerfStudio integration: Call into D3D9.DLL's D3DPERF_BeginEvent() (this gets intercepted by PerfStudio even in GL mode).
			if ( g_pShaderDeviceMgrDx8->m_pBeginEvent )
			{
				wchar_t wszName[128];
				mbstowcs( wszName, szName, 128 );

				g_pShaderDeviceMgrDx8->m_pBeginEvent( 0x2F2F2F2F, wszName );
			}
		#endif
	#elif defined(_X360 )
		char szPIXEventName[32];
		PIXifyName( szPIXEventName, szName );
		PIXBeginNamedEvent( color, szPIXEventName );
	#else // PC
 		if ( PIXError() )
 			return;

		wchar_t wszName[128];
		mbstowcs( wszName, szName, 128 );

		// Fire the PIX event, trapping for errors...
		if ( D3DPERF_BeginEvent( color, wszName ) < 0 )
		{
 			Warning( "PIX error Beginning %s event\n", szName );
 			IncrementPIXError();
		}
	#endif
#endif // #if defined( PIX_INSTRUMENTATION )
}