void DoScreenIndependantMessageBox(const ST::string& msg, MessageBoxFlags flags, MSGBOX_CALLBACK callback)
{
	SGPBox const centering_rect = {0, 0, SCREEN_WIDTH, INV_INTERFACE_START_Y };
	switch (ScreenID const screen = guiCurrentScreen)
	{
		case AUTORESOLVE_SCREEN:
		case GAME_SCREEN:        DoMessageBox(                    MSG_BOX_BASIC_STYLE,    msg, screen, flags, callback, &centering_rect); break;
		case LAPTOP_SCREEN:      DoLapTopSystemMessageBoxWithRect(MSG_BOX_LAPTOP_DEFAULT, msg, screen, flags, callback, &centering_rect); break;
		case MAP_SCREEN:         DoMapMessageBoxWithRect(         MSG_BOX_BASIC_STYLE,    msg, screen, flags, callback, &centering_rect); break;
		case OPTIONS_SCREEN:     DoOptionsMessageBoxWithRect(                             msg, screen, flags, callback, &centering_rect); break;
		case SAVE_LOAD_SCREEN:   DoSaveLoadMessageBoxWithRect(                            msg, screen, flags, callback, &centering_rect); break;
		default:
			break;
	}
}