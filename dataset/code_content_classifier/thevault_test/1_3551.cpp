bool CShaderAPIDx8::IsDepthWriteEnabled( StateSnapshot_t id ) const
{
	LOCK_SHADERAPI();
	return m_TransitionTable.GetSnapshot(id).m_DepthTestState.m_ZWriteEnable;
}