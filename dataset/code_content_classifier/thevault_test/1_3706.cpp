void *CMaterialSystem::QueryInterface( const char *pInterfaceName )
{
	// Returns various interfaces supported by the shader API dll
	void *pInterface = QueryShaderAPI( pInterfaceName );
	if ( pInterface )
		return pInterface;

	CreateInterfaceFn factory = Sys_GetFactoryThis();	// This silly construction is necessary
	return factory( pInterfaceName, NULL );				// to prevent the LTCG compiler from crashing.
}