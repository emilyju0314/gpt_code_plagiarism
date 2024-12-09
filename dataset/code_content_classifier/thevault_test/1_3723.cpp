ITexture *CMaterialSystem::CreateGamerpicTexture(
	const char			*pTextureName,
	const char			*pTextureGroupName,
	int					nFlags )
{
	return CreateProceduralTexture( pTextureName, pTextureGroupName, g_GamerpicSize, g_GamerpicSize, g_GamerpicFormat, nFlags );
}