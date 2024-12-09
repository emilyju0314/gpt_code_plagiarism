void CShaderAPIDx8::BeginOcclusionQueryDrawing( ShaderAPIOcclusionQuery_t handle )
{
	IDirect3DQuery9 *pQuery = (IDirect3DQuery9 *)handle;

	HRESULT hResult = pQuery->Issue( D3DISSUE_BEGIN );
	Assert( hResult == D3D_OK );
}