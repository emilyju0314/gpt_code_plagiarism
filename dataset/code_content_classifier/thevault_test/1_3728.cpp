void CMaterialSystem::RecomputeAllStateSnapshots()
{
	g_pShaderAPI->ClearSnapshots();
	for (MaterialHandle_t i = FirstMaterial(); i != InvalidMaterial(); i = NextMaterial(i) )
	{
		GetMaterialInternal(i)->RecomputeStateSnapshots();
	}
	g_pShaderAPI->ResetRenderState();
}