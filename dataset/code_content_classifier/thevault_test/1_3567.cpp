void CShaderAPIDx8::SetFastClipPlane( const float *pPlane )
{	
	LOCK_SHADERAPI();
	D3DXPLANE plane;
	plane.a = pPlane[0];
	plane.b = pPlane[1];
	plane.c = pPlane[2];
	plane.d = -pPlane[3];
	if ( plane != m_DynamicState.m_FastClipPlane )
	{
		UpdateVertexShaderFogParams();

		m_DynamicState.m_FastClipPlane = plane;

		// Mark a dirty bit so when it comes time to commit view + projection transforms,
		// we also update the fast clip matrices
		m_DynamicState.m_bFastClipPlaneChanged = true;

		m_DynamicState.m_TransformChanged[MATERIAL_PROJECTION] |= STATE_CHANGED;
	}
}