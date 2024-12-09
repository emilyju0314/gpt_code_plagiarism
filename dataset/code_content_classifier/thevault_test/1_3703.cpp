CreateInterfaceFn CMaterialSystem::CreateShaderAPI( char const* pShaderDLL )
{
	if ( !pShaderDLL )
		return 0;

	// Clean up the old shader
	DestroyShaderAPI();

	// Load the new shader
	m_ShaderHInst = Sys_LoadModule( pShaderDLL );

	// Error loading the shader
	if ( !m_ShaderHInst )
		return 0;

	// Get our class factory methods...
	return Sys_GetFactory( m_ShaderHInst );
}