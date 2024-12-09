void *CMaterialSystem::QueryShaderAPI( const char *pInterfaceName )
{
	// Returns various interfaces supported by the shader API dll
	void *pInterface = NULL;
	if (m_ShaderAPIFactory)
	{
		pInterface = m_ShaderAPIFactory( pInterfaceName, NULL );
	}
	return pInterface;
}