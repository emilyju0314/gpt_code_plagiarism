void CShaderAPIDx8::ApplyZBias( const DepthTestState_t& shaderState )
{
	// PORTAL 2 hack: Disable slope scale z bias for decals if we have a poly offset matrix set. This avoids decals and overlays rendering
	// on top of other stuff through portal views on the PS3.
	float a = m_DynamicState.m_FastClipEnabled ? 0.0f : m_ZBiasDecal.m_flOOSlopeScaleDepthBias;
    float b = m_ZBias.m_flOOSlopeScaleDepthBias;
    float c = m_ZBiasDecal.m_flOODepthBias;
    float d = m_ZBias.m_flOODepthBias;

	// bias = (s * D3DRS_SLOPESCALEDEPTHBIAS) + D3DRS_DEPTHBIAS, where s is the maximum depth slope of the triangle being rendered
    if ( g_pHardwareConfig->Caps().m_ZBiasAndSlopeScaledDepthBiasSupported )
    {
		float fSlopeScaleDepthBias, fDepthBias;
		if ( shaderState.m_ZBias == SHADER_POLYOFFSET_DECAL )
		{
			fSlopeScaleDepthBias = a;
			fDepthBias = c;
		}
		else if ( shaderState.m_ZBias == SHADER_POLYOFFSET_SHADOW_BIAS )
		{
			fSlopeScaleDepthBias = m_fShadowSlopeScaleDepthBias;
			fDepthBias = m_fShadowDepthBias;
			m_TransitionTable.SetShadowDepthBiasValuesDirty( false );
		}
		else // assume SHADER_POLYOFFSET_DISABLE
		{
			fSlopeScaleDepthBias = b;
			fDepthBias = d;
		}

		if( ReverseDepthOnX360() )
		{
			fSlopeScaleDepthBias = -fSlopeScaleDepthBias;
			fDepthBias = -fDepthBias;
		}

		SetRenderState( D3DRS_SLOPESCALEDEPTHBIAS, *((DWORD*) (&fSlopeScaleDepthBias)) );
		SetRenderState( D3DRS_DEPTHBIAS, *((DWORD*) (&fDepthBias)) );
	} 
	else
	{
		MarkAllUserClipPlanesDirty();
		m_DynamicState.m_TransformChanged[MATERIAL_PROJECTION] |= STATE_CHANGED;
	}
}