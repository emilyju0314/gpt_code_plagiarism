void SimulateButton(const Sint32& pWhich, const Uint8& pButton, bool bDown)
	{
		if (m_arrayControllers[pWhich].controller != nullptr && m_arrayControllers[pWhich].bEnabled == true)
		{
			m_arrayControllers[pWhich].mControllerButtons[pButton] = bDown;
		}
	}