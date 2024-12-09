const char* GetButtonName(const Sint32& pButton)
	{
		if (pButton == MOUSE_BUTTON_LEFT) return MOUSE_BUTTON_LEFT_NAME;
		if (pButton == MOUSE_BUTTON_MIDDLE) return MOUSE_BUTTON_MIDDLE_NAME;
		if (pButton == MOUSE_BUTTON_RIGHT) return MOUSE_BUTTON_RIGHT_NAME;

		if (pButton == MOUSE_BUTTON_WHEELUP) return MOUSE_BUTTON_WHEELUP_NAME;
		if (pButton == MOUSE_BUTTON_WHEELDOWN) return MOUSE_BUTTON_WHEELDOWN_NAME;

		return SDL_GetKeyName(pButton);
	}