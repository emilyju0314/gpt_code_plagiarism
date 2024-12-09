Sint32 GetButtonIndex(const char* pButton)
	{
		std::string s(pButton);
		if (s == MOUSE_BUTTON_LEFT_NAME) return MOUSE_BUTTON_LEFT;
		if (s == MOUSE_BUTTON_MIDDLE_NAME) return MOUSE_BUTTON_MIDDLE;
		if (s == MOUSE_BUTTON_RIGHT_NAME) return MOUSE_BUTTON_RIGHT;

		if (s == MOUSE_BUTTON_WHEELUP_NAME) return MOUSE_BUTTON_WHEELUP;
		if (s == MOUSE_BUTTON_WHEELDOWN_NAME) return MOUSE_BUTTON_WHEELDOWN;
		s.clear();

		return SDL_GetKeyFromName(pButton);
	}