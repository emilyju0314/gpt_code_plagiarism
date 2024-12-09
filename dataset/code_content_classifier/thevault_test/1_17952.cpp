void Connect(const Sint32& pWhich)
	{
		if (pWhich <= ENUM_GAMEPAD_MAX)
		{
			if (m_arrayControllers[pWhich].controller == nullptr)
			{
				m_arrayControllers[pWhich].controller = SDL_GameControllerOpen(pWhich);
				m_arrayControllers[pWhich].pszDeviceName = SDL_GameControllerName(m_arrayControllers[pWhich].controller);


				m_arrayControllers[pWhich].bEnabled = true;
				Flush(pWhich);

				printf("Connected GamePad '%s' into port %d\n", m_arrayControllers[pWhich].pszDeviceName, pWhich);
			}
			else
			{
				// Error
				printf("Failed to connect GamePad to port %d as port is already in use.\n", pWhich);
			}
		}
		else
		{
			// Error
			printf("Failed to connect GamePad to port %d as the index is out of range (Max Controllers: %d).\n", pWhich, ENUM_GAMEPAD_MAX);
		}
	}