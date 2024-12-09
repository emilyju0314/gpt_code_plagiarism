void CShaderAPIDx8::ClearSnapshots()
{
	LOCK_SHADERAPI();
	m_TransitionTable.Reset();
	InitRenderState();
}