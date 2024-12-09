void CShaderAPIDx8::GetMaxToRender( IMesh *pMesh, bool bMaxUntilFlush, int *pMaxVerts, int *pMaxIndices )
{
	LOCK_SHADERAPI();
	MeshMgr()->GetMaxToRender( pMesh, bMaxUntilFlush, pMaxVerts, pMaxIndices );
}