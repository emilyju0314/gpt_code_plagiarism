IMaterial *CMaterialSystem::FindProceduralMaterial( const char *pMaterialName, const char *pTextureGroupName, KeyValues *pVMTKeyValues )
{
	// We need lower-case symbols for this to work
	int nLen = Q_strlen( pMaterialName ) + 1;
	char *pTemp = (char*)stackalloc( nLen );
	Q_strncpy( pTemp, pMaterialName, nLen );
	Q_strlower( pTemp );
	Q_FixSlashes( pTemp, '/' );

	// 'true' causes the search to find procedural materials
	IMaterialInternal *pMaterial = m_MaterialDict.FindMaterial( pTemp, true );
	if ( pMaterial )
	{
		if ( pVMTKeyValues != NULL )
		{
			pVMTKeyValues->deleteThis();
		}
	}
	else
	{
		if ( pVMTKeyValues != NULL )
		{
			pMaterial = IMaterialInternal::CreateMaterial( pMaterialName, pTextureGroupName, pVMTKeyValues );
			AddMaterialToMaterialList( static_cast<IMaterialInternal*>( pMaterial ) );
		}
		else
		{
			pMaterial = g_pErrorMaterial;
		}
	}

	return pMaterial->GetQueueFriendlyVersion();
}