bool CShaderAPIDx8::UsesVertexAndPixelShaders( StateSnapshot_t id ) const
{
	LOCK_SHADERAPI();
	return m_TransitionTable.GetSnapshotShader(id).m_VertexShader != INVALID_SHADER;
}