void CMaterialSystem::GetShaderFallback( const char *pShaderName, char *pFallbackShader, int nFallbackLength )
{
	// FIXME: This is pretty much a hack. We need a better way for the
	// editor to get ahold of shader fallbacks
	int nCount = ShaderCount();
	IShader** ppShaderList = (IShader**)stackalloc( nCount * sizeof(IShader) );
	GetShaders( 0, nCount, ppShaderList );

	do
	{
		int i;
		for ( i = 0; i < nCount; ++i )
		{
			if ( !Q_stricmp( pShaderName, ppShaderList[i]->GetName() ) )
				break;
		}

		// Didn't find a match!
		if ( i == nCount )
		{
			Q_strncpy( pFallbackShader, "wireframe", nFallbackLength );
			return;
		}

		// Found a match
		// FIXME: Theoretically, getting fallbacks should require a param list
		// In practice, it looks rare or maybe even neved done
		const char *pFallback = ppShaderList[i]->GetFallbackShader( NULL );
		if ( !pFallback )
		{
			Q_strncpy( pFallbackShader, pShaderName, nFallbackLength );
			return;
		}
		else
		{
			pShaderName = pFallback;
		}
	} while (true);
}