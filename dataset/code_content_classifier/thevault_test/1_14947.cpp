ScreenID InitializeJA2(void)
try
{
	gfWorldLoaded = FALSE;

	// Load external text
	LoadAllExternalText();

	gsRenderCenterX = 805;
	gsRenderCenterY = 805;

	// Init animation system
	InitAnimationSystem();

	// Init lighting system
	InitLightingSystem();

	// Init dialog queue system
	InitalizeDialogueControl();

	InitStrategicEngine();

	//needs to be called here to init the SectorInfo struct
	InitStrategicMovementCosts( );

	// Init tactical engine
	InitTacticalEngine();

	// Init timer system
	//Moved to the splash screen code.
	//InitializeJA2Clock( );

	// INit shade tables
	BuildShadeTable( );

	// INit intensity tables
	BuildIntensityTable( );

	// Initailize World
	InitializeWorld();

	InitTileCache( );

	InitMercPopupBox( );

	if(GameMode::getInstance()->isEditorMode())
	{
		//UNCOMMENT NEXT LINE TO ALLOW FORCE UPDATES...
		//LoadGlobalSummary();
		if( gfMustForceUpdateAllMaps )
		{
			ApologizeOverrideAndForceUpdateEverything();
		}
	}

	switch (GameMode::getInstance()->getMode())
	{
		case GAME_MODE_EDITOR:
			SLOGI("Beginning JA2 using -editor commandline argument...");
			gfAutoLoadA9 = FALSE;
			goto editor;

		case GAME_MODE_EDITOR_AUTO:
			SLOGI("Beginning JA2 using -editorauto commandline argument...");
			gfAutoLoadA9 = TRUE;
editor:
			//also set the sector
			SetWorldSectorInvalid();
			gfIntendOnEnteringEditor = TRUE;
			gGameOptions.fGunNut     = TRUE;
			return GAME_SCREEN;

		default: return INIT_SCREEN;
	}
}
catch (const std::runtime_error& ex)
{
	SET_ERROR(ST::format("InitializeJA2: {}", ex.what()));
	return ERROR_SCREEN;
}