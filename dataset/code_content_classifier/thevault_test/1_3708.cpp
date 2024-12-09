CreateInterfaceFn CMaterialSystem::Init( char const* pShaderAPIDLL,
										IMaterialProxyFactory *pMaterialProxyFactory,
										CreateInterfaceFn fileSystemFactory,
										CreateInterfaceFn cvarFactory )
{
	SetShaderAPI( pShaderAPIDLL );

	s_TempCVarFactory = cvarFactory;
	s_TempFileSystemFactory = fileSystemFactory;
	if ( !Connect( TempCreateInterface ) )
		return 0;

	if (Init() != INIT_OK)
		return NULL;

	// save the proxy factory
	m_pMaterialProxyFactory = pMaterialProxyFactory;

	return m_ShaderAPIFactory;
}