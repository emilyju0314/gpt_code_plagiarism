void CMatLightmaps::ResetMaterialLightmapPageInfo( void )
{
	for (MaterialHandle_t i = GetMaterialDict()->FirstMaterial(); i != GetMaterialDict()->InvalidMaterial(); i = GetMaterialDict()->NextMaterial(i) )
	{
		IMaterialInternal *pMaterial = GetMaterialInternal(i);
		pMaterial->SetMinLightmapPageID( 9999 );
		pMaterial->SetMaxLightmapPageID( -9999 );
		pMaterial->SetNeedsWhiteLightmap( false );
	}
}