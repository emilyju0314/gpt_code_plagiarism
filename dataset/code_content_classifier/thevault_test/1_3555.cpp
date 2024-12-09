void CShaderAPIDx8::BeginFrame()
{
	LOCK_SHADERAPI();

	if ( m_bResetRenderStateNeeded )
	{
		ResetRenderState( false );
		m_bResetRenderStateNeeded = false;
	}

#if ALLOW_SMP_ACCESS
	Dx9Device()->SetASyncMode( mat_use_smp.GetBool() );
#endif

	++m_CurrentFrame;
	m_nTextureMemoryUsedLastFrame = 0;
	m_bCSMsValidThisFrame = false;
}