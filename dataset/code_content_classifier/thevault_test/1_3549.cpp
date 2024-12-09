bool CShaderAPIDx8::IsTranslucent( StateSnapshot_t id ) const
{
	LOCK_SHADERAPI();
	const ShadowState_t& snapshot = m_TransitionTable.GetSnapshot(id);
	return snapshot.m_AlphaBlendState.m_AlphaBlendEnable && !snapshot.m_AlphaBlendState.m_AlphaBlendEnabledForceOpaque;
}