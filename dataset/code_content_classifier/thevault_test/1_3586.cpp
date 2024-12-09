void CShaderAPIDx8::SetupSelectionModeVisualizationState()
{
	Dx9Device()->SetRenderState( D3DRS_CULLMODE, D3DCULL_NONE );

	D3DXMATRIX ident;
	D3DXMatrixIdentity( &ident );
	SetVertexShaderConstantInternal( VERTEX_SHADER_VIEWPROJ, ident, 4 );
	SetVertexShaderConstantInternal( VERTEX_SHADER_MODELVIEWPROJ, ident, 4 );
	SetVertexShaderConstantInternal( VERTEX_SHADER_MODEL, ident, 3 * NUM_MODEL_TRANSFORMS );
}