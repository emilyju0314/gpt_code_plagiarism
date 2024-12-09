void CShaderAPIDx8::EnableFastClip( bool bEnable )
{
	LOCK_SHADERAPI();
	if( m_DynamicState.m_FastClipEnabled != bEnable )
	{
		UpdateVertexShaderFogParams();

		m_DynamicState.m_FastClipEnabled = bEnable;

		m_DynamicState.m_TransformChanged[MATERIAL_PROJECTION] |= STATE_CHANGED;
	}
}