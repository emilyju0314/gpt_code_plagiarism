void CShaderAPIDx8::MarkAllUserClipPlanesDirty()
{
	m_DynamicState.m_UserClipPlaneChanged |= ( 1 << g_pHardwareConfig->MaxUserClipPlanes() ) - 1;
	m_DynamicState.m_bFastClipPlaneChanged = true;
}