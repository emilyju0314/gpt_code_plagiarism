int CShaderAPIDx8::OcclusionQuery_GetNumPixelsRendered( ShaderAPIOcclusionQuery_t handle, bool bFlush )
{
	LOCK_SHADERAPI();
	IDirect3DQuery9 *pQuery = (IDirect3DQuery9 *)handle;

	DWORD nPixels;
	HRESULT hResult = pQuery->GetData( &nPixels, sizeof( nPixels ), bFlush ? D3DGETDATA_FLUSH : 0 );

	// This means that the query will not finish and resulted in an error, game should use
	// the previous query's results and not reissue the query
	if ( hResult == D3DERR_DEVICELOST )
		return OCCLUSION_QUERY_RESULT_ERROR;

	// This means the query isn't finished yet, game will have to use the previous query's
	// results and not reissue the query; wait for query to finish later.
	if ( hResult == S_FALSE )
		return OCCLUSION_QUERY_RESULT_PENDING;

	// NOTE: This appears to work around a driver bug for ATI on Vista
	if ( nPixels & 0x80000000 )
	{
		nPixels = 0;
	}
	return nPixels;
}