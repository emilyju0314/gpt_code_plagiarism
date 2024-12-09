void CMatLightmaps::EnumerateMaterials( void )
{
	// iterate in sorted order
	int id = 0;
	for (MaterialHandle_t i = GetMaterialDict()->FirstMaterial(); i != GetMaterialDict()->InvalidMaterial(); i = GetMaterialDict()->NextMaterial(i) )
	{
		GetMaterialInternal(i)->SetEnumerationID( id );
		++id;
	}
}