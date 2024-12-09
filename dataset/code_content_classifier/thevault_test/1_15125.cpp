void InitializeGame(void)
{
	UINT32				uiIndex;

	// Initlaize mouse subsystems
	MSYS_Init( );
	InitButtonSystem();
	InitCursors( );

	// Init Fonts
	InitializeFonts();

	InitTacticalSave();

	SLOGI("Version Label: %s", g_version_label);
	SLOGI("Version #:     %s", g_version_number);

	// Initialize Game Screens.
	for (uiIndex = 0; uiIndex < MAX_SCREENS; uiIndex++)
	{
		void (*const init)(void) = GameScreens[uiIndex].InitializeScreen;
		if (init) init();
	}

	//Init the help screen system
	InitHelpScreenSystem();

	//Loads the saved (if any) general JA2 game settings
	LoadGameSettings();

	//Initialize the Game options ( Gun nut, scifi and dif. levels
	InitGameOptions();

	// preload mapscreen graphics
	HandlePreloadOfMapGraphics( );

	guiCurrentScreen = INIT_SCREEN;
}