void CShaderAPIDx8::CallCommitFuncs( CommitFuncType_t func, bool bForce )
{
	// Don't bother committing anything if we're deactivated
	if ( IsDeactivated() )
		return;

	CUtlVector< StateCommitFunc_t > &funcList =	m_CommitFuncs[func];
	int nCount = funcList.Count();
	if ( nCount == 0 )
		return;

	for ( int i = 0; i < nCount; ++i )
	{
		funcList[i]( Dx9Device(), m_DesiredState, m_DynamicState, bForce );
	}
	ClearAllCommitFuncs( func );
}