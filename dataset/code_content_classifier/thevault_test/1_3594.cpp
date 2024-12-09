void CShaderAPIDx8::CommitPerPassStateChanges( StateSnapshot_t id )
{
	CommitPerPassVertexShaderTransforms();
	CommitPerPassFogMode( true );
	CommitPerPassXboxFixups();
	CallCommitFuncs( COMMIT_PER_PASS, false );
}