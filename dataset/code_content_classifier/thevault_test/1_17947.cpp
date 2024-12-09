float ButtonDown(const Sint32& pKey)
	{
		if (bEnabled == false) return 0.0f;

		if (pKey == MOUSE_BUTTON_WHEELUP) return (float)OnMouseWheelUp();
		if (pKey == MOUSE_BUTTON_WHEELDOWN) return (float)OnMouseWheelDown();
		return (float)mButton[pKey];
	}