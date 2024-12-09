void CShaderAPIDx8::ComputePolyOffsetMatrix( const D3DXMATRIX& matProjection, D3DXMATRIX &matProjectionOffset )
{
	// We never need to do this on hardware that can handle zbias
	if ( g_pHardwareConfig->Caps().m_ZBiasAndSlopeScaledDepthBiasSupported )
		return;

	float offsetVal = 
		-1.0f * (m_DesiredState.m_Viewport.MaxZ - m_DesiredState.m_Viewport.MinZ) /
		16384.0f;

	D3DXMATRIX offset;
	D3DXMatrixTranslation( &offset, 0.0f, 0.0f, offsetVal );
	D3DXMatrixMultiply( &matProjectionOffset, &matProjection, &offset );
}