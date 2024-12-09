void CShaderAPIDx8::CommitPerPassFogMode( bool bUsingVertexAndPixelShaders )
{
	if ( IsGameConsole() )
	{
		// FF fog not applicable on 360 / PS3
		return;
	}

	D3DFOGMODE dxFogMode = D3DFOG_NONE;
	if ( m_DynamicState.m_FogEnable )
	{
		dxFogMode = bUsingVertexAndPixelShaders ? D3DFOG_NONE : D3DFOG_LINEAR;
	}

	// Set fog mode if it's different than before.
	if( m_DynamicState.m_FogMode != dxFogMode )
	{
		SetSupportedRenderState( D3DRS_FOGVERTEXMODE, dxFogMode );
		m_DynamicState.m_FogMode = dxFogMode;
	}
}