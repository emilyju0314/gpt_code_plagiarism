IMaterial *CMaterialSystem::CreateMaterial( const char *pMaterialName, KeyValues *pVMTKeyValues )
{
	// For not, just create a material with no default settings
	IMaterialInternal* pMaterial = IMaterialInternal::CreateMaterial( pMaterialName, TEXTURE_GROUP_OTHER, pVMTKeyValues );
	pMaterial->IncrementReferenceCount();
	AddMaterialToMaterialList( pMaterial );
	return pMaterial->GetQueueFriendlyVersion();
}