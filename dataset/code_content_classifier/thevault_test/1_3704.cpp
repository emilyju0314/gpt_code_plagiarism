void CMaterialSystem::SetShaderAPI( char const *pShaderAPIDLL )
{
#if defined( _PS3 ) || defined( _OSX )
	return;
#endif

	if ( m_ShaderAPIFactory )
	{
		Warning( "Cannot set the shader API twice!\n" );
		return;
	}

	if ( !pShaderAPIDLL )
	{
		pShaderAPIDLL = "shaderapidx9";
	}

	// m_pShaderDLL is needed to spew driver info
	Assert( pShaderAPIDLL );
	int len = Q_strlen( pShaderAPIDLL ) + 1;
	m_pShaderDLL = new char[len];
	memcpy( m_pShaderDLL, pShaderAPIDLL, len );

	m_ShaderAPIFactory = CreateShaderAPI( pShaderAPIDLL );
	if ( !m_ShaderAPIFactory )
	{
		DestroyShaderAPI();
	}
}