void Disconnect(const Sint32& pWhich)
	{
		if (m_arrayControllers[pWhich].controller != nullptr)
		{
			printf("Disconnecting GamePad %d.\n", pWhich);
			Flush(pWhich);

			SDL_GameControllerClose(m_arrayControllers[pWhich].controller);
			m_arrayControllers[pWhich].pszDeviceName = "";
			m_arrayControllers[pWhich].bEnabled = false;
		}
	}