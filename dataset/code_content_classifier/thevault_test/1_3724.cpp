bool CMaterialSystem::UpdateLocalGamerpicTexture(
	ITexture			*pTexture, 
	DWORD				userIndex )
{
	Assert( pTexture != NULL );
	Assert( pTexture->GetActualWidth() == g_GamerpicSize && pTexture->GetActualHeight() == g_GamerpicSize );
	Assert( pTexture->GetImageFormat() == g_GamerpicFormat );
	Assert( userIndex >= 0 && userIndex < 4 );

	// lock
	CPixelWriter writer;
	g_pShaderAPI->ModifyTexture( ((ITextureInternal*)pTexture)->GetTextureHandle( 0 ) );
	g_pShaderAPI->TexLock( 0, 0, 0, 0, g_GamerpicSize, g_GamerpicSize, writer );

	// Write the gamerpic to the texture.
	BYTE *pBuf = (BYTE*)writer.GetPixelMemory();
	DWORD retVal = XUserReadGamerPicture( userIndex, FALSE, pBuf, g_GamerpicSize * writer.GetPixelSize(), g_GamerpicSize * writer.GetPixelSize(), NULL );

	// unlock
	g_pShaderAPI->TexUnlock();

	return (retVal == ERROR_SUCCESS);
}