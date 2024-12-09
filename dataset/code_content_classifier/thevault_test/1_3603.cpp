void CShaderAPIDx8::Bind( IMaterial* pMaterial )
{
	LOCK_SHADERAPI();
	IMaterialInternal* pMatInt = static_cast<IMaterialInternal*>( pMaterial );

	bool bMaterialChanged;
	if ( m_pMaterial && pMatInt && m_pMaterial->InMaterialPage() && pMatInt->InMaterialPage() )
	{
		bMaterialChanged = ( m_pMaterial->GetMaterialPage() != pMatInt->GetMaterialPage() );
	}
	else
	{
		bMaterialChanged = ( m_pMaterial != pMatInt ) || ( m_pMaterial && m_pMaterial->InMaterialPage() ) || ( pMatInt && pMatInt->InMaterialPage() );
	}

	if ( bMaterialChanged )
	{
#ifdef RECORDING
		RECORD_DEBUG_STRING( ( char * )pMaterial->GetName() );
		IShader *pShader = pMatInt->GetShader();
		if( pShader && pShader->GetName() )
		{
			RECORD_DEBUG_STRING( pShader->GetName() );
		}
		else
		{
			RECORD_DEBUG_STRING( "<NULL SHADER>" );
		}
#endif
		m_pMaterial = pMatInt;

#if ( defined( PIX_INSTRUMENTATION ) || defined( NVPERFHUD ) || ( defined( PLATFORM_POSIX ) && GLMDEBUG ) )
		PIXifyName( s_pPIXMaterialName, m_pMaterial->GetName() );
#endif

#ifdef _GAMECONSOLE
		if ( m_bInZPass )
		{
			if ( pMatInt->IsAlphaTested() || pMatInt->IsTranslucent() )
			{
				// we need to predicate render calls with this material to only occur during main rendering and not the z pass
				Dx9Device()->SetPredication( D3DPRED_ALL_RENDER );
			}
			else
			{
				Dx9Device()->SetPredication( 0 );
			}
		}
#endif
	}
}