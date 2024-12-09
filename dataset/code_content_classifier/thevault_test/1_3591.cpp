void CShaderAPIDx8::CompilePixelShaderLocalLights( CompiledLightingState_t *pCompiledState, int nLightCount, const MaterialLightingState_t *pOrigLightingState, bool bStaticLight )
{
#ifndef NDEBUG
	const char *materialName = m_pMaterial->GetName();
#endif

	// Total pixel shader lighting state for four lights
	for ( int i = 0; i < 6; i++ )
	{
		pCompiledState->m_PixelShaderLocalLights[i].Init();
	}

	if ( !pOrigLightingState )
		return;

	MaterialLightingState_t canonicalizedLightingState;
	const MaterialLightingState_t *pLightingState = CanonicalizeMaterialLightingStateForCSM( pOrigLightingState, canonicalizedLightingState, bStaticLight );
	
	nLightCount = pLightingState->m_nLocalLightCount;

	// Offset to create a point light from directional
	const float fFarAway = 10000.0f;

	// NOTE: Use maxlights so we can render instances with different #s of lights
	// without needing to change shader
	const int nNumLights = pLightingState->m_nLocalLightCount;
	int nIterCount = MIN( nLightCount, 3 );
	for ( int i = 0; i < nIterCount; ++i )
	{
		int nIndex = 2 * i;
		const LightDesc_t *light = &pLightingState->m_pLocalLightDesc[i];
		Assert( light->m_Type != MATERIAL_LIGHT_DISABLE );
		pCompiledState->m_PixelShaderLocalLights[nIndex].Init( light->m_Color.x, light->m_Color.y, light->m_Color.z, 0.0f );

		if ( light->m_Type == MATERIAL_LIGHT_DIRECTIONAL )
		{
			VectorMA( pLightingState->m_vecLightingOrigin, -fFarAway, light->m_Direction, pCompiledState->m_PixelShaderLocalLights[nIndex + 1].AsVector3D() ); 
		}
		else
		{
			VectorCopy( light->m_Position, pCompiledState->m_PixelShaderLocalLights[nIndex + 1].AsVector3D() );
		}
	}

	if ( nNumLights > 3 ) // At least four lights (our current max)
	{
		const LightDesc_t *light = &pLightingState->m_pLocalLightDesc[3];
		// Spread 4th light's constants across w components
		pCompiledState->m_PixelShaderLocalLights[0].w = light->m_Color.x;
		pCompiledState->m_PixelShaderLocalLights[1].w = light->m_Color.y;
		pCompiledState->m_PixelShaderLocalLights[2].w = light->m_Color.z;

		if ( light->m_Type == MATERIAL_LIGHT_DIRECTIONAL )
		{
			Vector vPos;
			VectorMA( pLightingState->m_vecLightingOrigin, -fFarAway, light->m_Direction, vPos ); 
			pCompiledState->m_PixelShaderLocalLights[3].w = vPos.x;
			pCompiledState->m_PixelShaderLocalLights[4].w = vPos.y;
			pCompiledState->m_PixelShaderLocalLights[5].w = vPos.z;
		}
		else
		{
			pCompiledState->m_PixelShaderLocalLights[3].w = light->m_Position.x;
			pCompiledState->m_PixelShaderLocalLights[4].w = light->m_Position.y;
			pCompiledState->m_PixelShaderLocalLights[5].w = light->m_Position.z;
		}
	}
}