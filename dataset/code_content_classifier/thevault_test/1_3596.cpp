void CShaderAPIDx8::PerformFullScreenStencilOperation( void )
{
	LOCK_SHADERAPI();

	// We'll be drawing a large quad in altered worldspace, user clip planes must be disabled
	SetRenderState( D3DRS_CLIPPLANEENABLE, 0 );

	ShaderUtil()->DrawClearBufferQuad( 0, 0, 0, 0, false, false, false );

	// Reset user clip plane state
	SetRenderState( D3DRS_CLIPPLANEENABLE, m_DynamicState.m_UserClipPlaneEnabled );
}