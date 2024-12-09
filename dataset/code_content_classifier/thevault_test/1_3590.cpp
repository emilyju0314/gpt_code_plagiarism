void CShaderAPIDx8::CompileVertexShaderLocalLights( CompiledLightingState_t *pCompiledState, int nLightCount, const MaterialLightingState_t *pOrigLightingState, bool bStaticLight )
{
	// For vertex shaders, we don't need to bother with the max instance lightcount
	// because we use static conditionals (NOTE: test this!! might be faster to
	// have lightcounts all be the same)
	
	MaterialLightingState_t canonicalizedLightingState;
	const MaterialLightingState_t *pLightingState = CanonicalizeMaterialLightingStateForCSM( pOrigLightingState, canonicalizedLightingState, bStaticLight );
	
	// We can just use the data for this specific instance
	nLightCount = MIN( pLightingState->m_nLocalLightCount, g_pHardwareConfig->MaxNumLights() );
	pCompiledState->m_nLocalLightCount = nLightCount;

	// Set the lighting state
	for ( int i = 0; i < nLightCount; ++i )
	{
		Vector4D *pDest = &pCompiledState->m_VertexShaderLocalLights[ i * 5 ];
		const LightDesc_t& light = pLightingState->m_pLocalLightDesc[ i ];
		Assert( light.m_Type != MATERIAL_LIGHT_DISABLE );

		// The first one is the light color (and light type code on DX9)
		float w = ( light.m_Type == MATERIAL_LIGHT_DIRECTIONAL ) ? 1.0f : 0.0f;
		pDest[0].Init( light.m_Color.x, light.m_Color.y, light.m_Color.z, w);

		// The next constant holds the light direction (and light type code on DX9)
		w = ( light.m_Type == MATERIAL_LIGHT_SPOT ) ? 1.0f : 0.0f;
		if ( light.m_Type == MATERIAL_LIGHT_POINT )
		{
			pDest[1].Init( 0, 0, 0, w );
		}
		else
		{
			pDest[1].Init( light.m_Direction.x, light.m_Direction.y, light.m_Direction.z, w );
		}

		// The next constant holds the light position
		pDest[2].Init( light.m_Position.x, light.m_Position.y, light.m_Position.z, 1.0f );

		// The next constant holds exponent, stopdot, stopdot2, 1 / (stopdot - stopdot2)
		if ( light.m_Type == MATERIAL_LIGHT_SPOT )
		{
			float oodot = light.OneOverThetaDotMinusPhiDot();
			pDest[3].Init( light.m_Falloff, light.m_ThetaDot, light.m_PhiDot, oodot );
		}
		else
		{
			pDest[3].Init( 0, 1, 1, 1 );
		}

		// The last constant holds attenuation0, attenuation1, attenuation2
		pDest[4].Init( light.m_Attenuation0, light.m_Attenuation1, light.m_Attenuation2, 0.0f );
	}

	// Vertex Shader loop counter for number of lights (Only the .x component is used by our shaders) 
	// .x is the iteration count, .y is the initial value and .z is the increment step 
	int *pLoopControl = pCompiledState->m_VertexShaderLocalLightLoopControl;
	pLoopControl[0] = nLightCount; pLoopControl[1] = 0; pLoopControl[2] = 1; pLoopControl[3] = 0;

	// Enable lights using vertex shader static flow control
	int *pEnable = pCompiledState->m_VertexShaderLocalLightEnable;
	for ( int i = 0; i < VERTEX_SHADER_LIGHT_ENABLE_BOOL_CONST_COUNT; ++i )
	{
		pEnable[i] = ( i < nLightCount ) ? 1 : 0;
	}
}