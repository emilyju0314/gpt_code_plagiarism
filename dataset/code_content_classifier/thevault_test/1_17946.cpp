void SimulateButton(const Sint32& pKey, bool bDown)
	{
		if (bEnabled == false)
			return;

		mButton[pKey] = bDown;
	}