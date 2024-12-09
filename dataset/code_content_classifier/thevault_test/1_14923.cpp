void InitJA2SplashScreen(void)
{
	InitializeJA2Clock();

	if(isEnglishVersion())
	{
		ClearMainMenu();
	}
	else
	{
		const char* const ImageFile = GetMLGFilename(MLG_SPLASH);
		BltVideoSurfaceOnceWithStretch(FRAME_BUFFER, ImageFile);
	}

	InvalidateScreen();
	RefreshScreen();

	guiSplashStartTime = GetJA2Clock();
}