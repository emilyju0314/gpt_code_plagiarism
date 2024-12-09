void CShaderAPIDx8::CommitPerPassXboxFixups()
{
#if defined( _X360 )
	// send updated shader constants to gpu
	WriteShaderConstantsToGPU();

	// sRGB write state may have changed after RT set, have to re-set correct RT
	SetRenderTargetInternalXbox( m_hCachedRenderTarget );
#endif
}