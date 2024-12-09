D3DCULL CShaderAPIDx8::GetCullMode() const
{
	Assert( m_pMaterial );

	if ( m_pMaterial->GetMaterialVarFlag( MATERIAL_VAR_NOCULL ) )
		return D3DCULL_NONE;

	return m_DynamicState.m_DesiredCullMode;
}