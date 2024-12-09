void Flush(const Sint32& pWhich)
	{
		if (pWhich <= ENUM_GAMEPAD_MAX)
		{
			if (m_arrayControllers[pWhich].controller != nullptr)
			{
				m_arrayControllers[pWhich].mControllerButtons.clear();
			}
		}
	}