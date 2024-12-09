void CShaderAPIDx8::EnableAlphaToCoverage( void )
{
	if( !g_pHardwareConfig->ActualCaps().m_bSupportsAlphaToCoverage || !IsAAEnabled() )
		return;

	if ( IsPC() && ( m_PresentParameters.MultiSampleType < D3DMULTISAMPLE_4_SAMPLES ) )
		return;

	D3DRENDERSTATETYPE renderState = (D3DRENDERSTATETYPE)g_pHardwareConfig->Caps().m_AlphaToCoverageState;
	SetRenderState( renderState, g_pHardwareConfig->Caps().m_AlphaToCoverageEnableValue );	// Vendor dependent state
}