bool CMaterialSystem::UpdateRemoteGamerpicTexture(
	ITexture			*pTexture,
	XUID				xuid )
{
	Assert( pTexture != NULL );
	Assert( pTexture->GetActualWidth() == g_GamerpicSize && pTexture->GetActualHeight() == g_GamerpicSize );
	Assert( pTexture->GetImageFormat() == g_GamerpicFormat );

	//
	// Read the remote player's profile.
	//

	const DWORD xuidCount = 1;
	XUID xuids[xuidCount];
	xuids[0] = xuid;

	const DWORD settingIdCount = 1;
	DWORD settingIds[settingIdCount];
	settingIds[0] = XPROFILE_GAMERCARD_PICTURE_KEY;

	// Get the size of the results.
	DWORD resultsSize = 0;
	DWORD retVal = XUserReadProfileSettingsByXuid( 0, XBX_GetPrimaryUserId(), xuidCount, xuids, settingIdCount, settingIds, &resultsSize, 0, 0 );
	if ( retVal != ERROR_INSUFFICIENT_BUFFER )
	{
		return false;
	}

	Assert( resultsSize > 0 );

	// Get the profile with the correct results size.
	CArrayAutoPtr<unsigned char> spResultsBuffer( new unsigned char[resultsSize] );
	XUSER_READ_PROFILE_SETTING_RESULT *pResults = (XUSER_READ_PROFILE_SETTING_RESULT*)spResultsBuffer.Get();
	retVal = XUserReadProfileSettingsByXuid( 0, 0, xuidCount, xuids, settingIdCount, settingIds, &resultsSize, pResults, 0 );
	if ( retVal != ERROR_SUCCESS || pResults->dwSettingsLen == 0 )
	{
		return false;
	}

	// lock
	CPixelWriter writer;
	g_pShaderAPI->ModifyTexture( ((ITextureInternal*)pTexture)->GetTextureHandle( 0 ) );
	g_pShaderAPI->TexLock( 0, 0, 0, 0, g_GamerpicSize, g_GamerpicSize, writer );

	// Write the gamerpic to the texture.
	BYTE *pBuf = (BYTE*)writer.GetPixelMemory();
	retVal = XUserReadGamerPictureByKey( &(pResults->pSettings[0].data), FALSE, pBuf, g_GamerpicSize * writer.GetPixelSize(), g_GamerpicSize * writer.GetPixelSize(), NULL );

	// unlock
	g_pShaderAPI->TexUnlock();

	return (retVal == ERROR_SUCCESS);
}