ShaderAPIOcclusionQuery_t CShaderAPIDx8::CreateOcclusionQueryObject( void )
{
	// don't allow this on <80 because it falls back to wireframe in that case
	if( m_DeviceSupportsCreateQuery == 0 )
		return INVALID_SHADERAPI_OCCLUSION_QUERY_HANDLE;

	// While we're deactivated, m_OcclusionQueryObjects just holds NULL pointers.
	// Create a dummy one here and let ReacquireResources create the actual D3D object.
	if ( IsDeactivated() )
		return INVALID_SHADERAPI_OCCLUSION_QUERY_HANDLE;

	IDirect3DQuery9 *pQuery = NULL;
	HRESULT hr = Dx9Device()->CreateQuery( D3DQUERYTYPE_OCCLUSION, &pQuery );
	return ( hr == D3D_OK ) ? (ShaderAPIOcclusionQuery_t)pQuery : INVALID_SHADERAPI_OCCLUSION_QUERY_HANDLE;
}