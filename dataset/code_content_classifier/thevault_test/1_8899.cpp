bool SimulateRightStickWithDpad(const SDL_Event &event, ControllerButtonEvent ctrl_event)
{
	if (sgOptions.Controller.bDpadHotkeys)
		return false;
	static bool simulating = false;
	if (ctrl_event.button == ControllerButton_BUTTON_BACK) {
		if (ctrl_event.up && simulating) {
			rightStickX = rightStickY = 0;
			simulating = false;
		}
		return false;
	}
	if (!IsControllerButtonPressed(ControllerButton_BUTTON_BACK))
		return false;
	switch (ctrl_event.button) {
	case ControllerButton_BUTTON_DPAD_LEFT:
		rightStickX = ctrl_event.up ? 0 : -1;
		break;
	case ControllerButton_BUTTON_DPAD_RIGHT:
		rightStickX = ctrl_event.up ? 0 : 1;
		break;
	case ControllerButton_BUTTON_DPAD_UP:
		rightStickY = ctrl_event.up ? 0 : 1;
		break;
	case ControllerButton_BUTTON_DPAD_DOWN:
		rightStickY = ctrl_event.up ? 0 : -1;
		break;
	default:
		return false;
	}
	simulating = !(rightStickX == 0 && rightStickY == 0);

	return true;
}