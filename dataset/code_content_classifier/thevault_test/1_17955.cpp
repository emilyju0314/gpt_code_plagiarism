float ButtonDown(const Uint8& pButton, const GamePadIndex& iIndex)
	{
		float val = 0.0f;
		if (m_arrayControllers[(Sint32)iIndex].bEnabled == false) return val;

		if (pButton >= SDL_CONTROLLER_BUTTON_MAX)
		{
			switch (pButton)
			{
			case GAMEPAD_BUTTON_LTRIGGER:
				val = GetAxisFloat((Sint32)iIndex, SDL_CONTROLLER_AXIS_TRIGGERLEFT);
				break;

			case GAMEPAD_BUTTON_RTRIGGER:
				val = GetAxisFloat((Sint32)iIndex, SDL_CONTROLLER_AXIS_TRIGGERRIGHT);
				break;

			case GAMEPAD_BUTTON_LSTICK_UP:
				val = -GetAxisFloat((Sint32)iIndex, SDL_CONTROLLER_AXIS_LEFTY);
				break;

			case GAMEPAD_BUTTON_LSTICK_DOWN:
				val = GetAxisFloat((Sint32)iIndex, SDL_CONTROLLER_AXIS_LEFTY, true);
				break;

			case GAMEPAD_BUTTON_LSTICK_LEFT:
				val = -GetAxisFloat((Sint32)iIndex, SDL_CONTROLLER_AXIS_LEFTX);
				break;

			case GAMEPAD_BUTTON_LSTICK_RIGHT:
				val = GetAxisFloat((Sint32)iIndex, SDL_CONTROLLER_AXIS_LEFTX, true);
				break;

			case GAMEPAD_BUTTON_RSTICK_UP:
				val = -GetAxisFloat((Sint32)iIndex, SDL_CONTROLLER_AXIS_RIGHTY);
				break;

			case GAMEPAD_BUTTON_RSTICK_DOWN:
				val = GetAxisFloat((Sint32)iIndex, SDL_CONTROLLER_AXIS_RIGHTY, true);
				break;

			case GAMEPAD_BUTTON_RSTICK_LEFT:
				val = -GetAxisFloat((Sint32)iIndex, SDL_CONTROLLER_AXIS_RIGHTX);
				break;

			case GAMEPAD_BUTTON_RSTICK_RIGHT:
				val = GetAxisFloat((Sint32)iIndex, SDL_CONTROLLER_AXIS_RIGHTX, true);
				break;

			default:
				break;
			}
		}
		else
		{
			val = (float)m_arrayControllers[(Sint32)iIndex].mControllerButtons[pButton];
		}

		return val;
	}