Uint8 GetButtonIndex(const char* pButton)
	{
		std::string s(pButton);
		if (s == GAMEPAD_BUTTON_LTRIGGER_NAME) return GAMEPAD_BUTTON_LTRIGGER;
		if (s == GAMEPAD_BUTTON_RTRIGGER_NAME) return GAMEPAD_BUTTON_RTRIGGER;

		if (s == GAMEPAD_BUTTON_LSTICK_UP_NAME) return GAMEPAD_BUTTON_LSTICK_UP;
		if (s == GAMEPAD_BUTTON_LSTICK_DOWN_NAME) return GAMEPAD_BUTTON_LSTICK_DOWN;
		if (s == GAMEPAD_BUTTON_LSTICK_LEFT_NAME) return GAMEPAD_BUTTON_LSTICK_LEFT;
		if (s == GAMEPAD_BUTTON_LSTICK_RIGHT_NAME) return GAMEPAD_BUTTON_LSTICK_RIGHT;

		if (s == GAMEPAD_BUTTON_RSTICK_UP_NAME) return GAMEPAD_BUTTON_RSTICK_UP;
		if (s == GAMEPAD_BUTTON_RSTICK_DOWN_NAME) return GAMEPAD_BUTTON_RSTICK_DOWN;
		if (s == GAMEPAD_BUTTON_RSTICK_LEFT_NAME) return GAMEPAD_BUTTON_RSTICK_LEFT;
		if (s == GAMEPAD_BUTTON_RSTICK_RIGHT_NAME) return GAMEPAD_BUTTON_RSTICK_RIGHT;
		s.clear();

		return (Uint8)SDL_GameControllerGetButtonFromString(pButton);
	}