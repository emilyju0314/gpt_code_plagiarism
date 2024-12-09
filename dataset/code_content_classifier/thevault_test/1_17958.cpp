Sint16 GetAxisValue(const Sint32& pWhich, const Uint32& pAxis, bool bFlip)
	{
		Sint16 val = SDL_GameControllerGetAxis(m_arrayControllers[pWhich].controller, (SDL_GameControllerAxis)pAxis);
		if (pAxis == SDL_CONTROLLER_AXIS_TRIGGERLEFT)
		{
			if (val < GAMEPAD_TRIGGER_THRESHOLD)
			{
				val = 0;
			}
		}

		if (pAxis == SDL_CONTROLLER_AXIS_TRIGGERRIGHT)
		{
			if (val < GAMEPAD_TRIGGER_THRESHOLD)
			{
				val = 0;
			}
		}

		if (!bFlip)
		{
			if (pAxis == SDL_CONTROLLER_AXIS_LEFTY)
			{
				if (val > -GAMEPAD_THUMB_DEADZONE)
				{
					val = 0;
				}
			}

			if (pAxis == SDL_CONTROLLER_AXIS_LEFTX)
			{
				if (val > -GAMEPAD_THUMB_DEADZONE)
				{
					val = 0;
				}
			}
		}
		else
		{
			if (pAxis == SDL_CONTROLLER_AXIS_LEFTY)
			{
				if (val < GAMEPAD_THUMB_DEADZONE)
				{
					val = 0;
				}
			}

			if (pAxis == SDL_CONTROLLER_AXIS_LEFTX)
			{
				if (val < GAMEPAD_THUMB_DEADZONE)
				{
					val = 0;
				}
			}
		}

		return val;
	}