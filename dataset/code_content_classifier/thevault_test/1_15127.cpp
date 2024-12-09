void GameLoop(void)
try
{
	InputAtom InputEvent;
	ScreenID uiOldScreen = guiCurrentScreen;

	SGPPoint MousePos;
	GetMousePos(&MousePos);
	// Hook into mouse stuff for MOVEMENT MESSAGES
	MouseSystemHook(MOUSE_POS, MousePos.iX, MousePos.iY);
	MusicPoll();

	while (DequeueSpecificEvent(&InputEvent, MOUSE_EVENTS))
	{
		MouseSystemHook(InputEvent.usEvent, MousePos.iX, MousePos.iY);
	}


	if ( gfGlobalError )
	{
		guiCurrentScreen = ERROR_SCREEN;
	}


	//if we are to check for free space on the hard drive
	if( gfCheckForFreeSpaceOnHardDrive )
	{
		//only if we are in a screen that can get this check
		if( guiCurrentScreen == MAP_SCREEN || guiCurrentScreen == GAME_SCREEN || guiCurrentScreen == SAVE_LOAD_SCREEN )
		{
			// Make sure the user has enough hard drive space in home and temp dir
			uint64_t uiSpaceOnDrivePrivate = GCM->userPrivateFiles()->getFreeSpace("");
			uint64_t uiSpaceOnDriveTemp = GCM->tempFiles()->getFreeSpace("");
			uint64_t uiSpaceOnDrive = std::min(uiSpaceOnDrivePrivate, uiSpaceOnDriveTemp);
			if( uiSpaceOnDrive < REQUIRED_FREE_SPACE )
			{
				ST::string zSpaceOnDrive = ST::format("{.2f}", uiSpaceOnDrive / (FLOAT)BYTESINMEGABYTE);

				ST::string zText = st_format_printf(pMessageStrings[ MSG_LOWDISKSPACE_WARNING ], zSpaceOnDrive, "20");

				if( guiPreviousOptionScreen == MAP_SCREEN )
					DoMapMessageBox( MSG_BOX_BASIC_STYLE, zText, MAP_SCREEN, MSG_BOX_FLAG_OK, NULL );
				else
					DoMessageBox( MSG_BOX_BASIC_STYLE, zText, GAME_SCREEN, MSG_BOX_FLAG_OK, NULL, NULL );
			}
			gfCheckForFreeSpaceOnHardDrive = FALSE;
		}
	}

	// ATE: Force to be in message box screen!
	if ( gfInMsgBox )
	{
		guiPendingScreen = MSG_BOX_SCREEN;
	}

	if ( guiPendingScreen != NO_PENDING_SCREEN )
	{
		// Based on active screen, deinit!
		if( guiPendingScreen != guiCurrentScreen )
		{
			switch( guiCurrentScreen )
			{
				case MAP_SCREEN:
					if( guiPendingScreen != MSG_BOX_SCREEN )
					{
						EndMapScreen( FALSE );
					}
					break;
				case LAPTOP_SCREEN:
					ExitLaptop();
					break;
				default:
					break;
			}
		}

		// if the screen has chnaged
		if( uiOldScreen != guiPendingScreen )
		{
			// Set the fact that the screen has changed
			uiOldScreen = guiPendingScreen;

			HandleNewScreenChange( guiPendingScreen, guiCurrentScreen );
		}
		guiCurrentScreen = guiPendingScreen;
		guiPendingScreen = NO_PENDING_SCREEN;

	}



	uiOldScreen = (*(GameScreens[guiCurrentScreen].HandleScreen))();

	// if the screen has chnaged
	if( uiOldScreen != guiCurrentScreen )
	{
		HandleNewScreenChange( uiOldScreen, guiCurrentScreen );
		guiCurrentScreen = uiOldScreen;
	}

	RefreshScreen();

	guiGameCycleCounter++;

	UpdateClock();

}
catch (std::exception const& e)
{
	guiPreviousOptionScreen = guiCurrentScreen;
	char const* what;
	char const* success = "failed";
	char const* attach  = "";

	if (gfEditMode && GameMode::getInstance()->isEditorMode())
	{
		what = "map";
		if (SaveWorldAbsolute("error.dat"))
		{
			success = "succeeded (error.dat)";
			attach  = " Do not forget to attach the map.";
		}
	}
	else
	{
		what = "savegame";
		if (SaveGame(SAVE__ERROR_NUM, "error savegame"))
		{
			success = "succeeded (error.sav)";
			attach  = " Do not forget to attach the savegame.";
		}
	}
	char msg[2048];
	snprintf(msg, lengthof(msg),
		"%s\n"
		"Creating an emergency %s %s.\n"
		"Please report this error with a description of the circumstances.%s",
		e.what(), what, success, attach
	);
	throw std::runtime_error(msg);
}