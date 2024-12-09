bool CShaderAPIDx8::IsAlphaTested( StateSnapshot_t id ) const
{
	LOCK_SHADERAPI();
	return m_TransitionTable.GetSnapshot(id).m_AlphaTestAndMiscState.m_AlphaTestEnable;
}