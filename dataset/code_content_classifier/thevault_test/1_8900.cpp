bool ProcessControllerMotion(const SDL_Event &event, ControllerButtonEvent ctrl_event)
{
#ifndef USE_SDL1
	GameController *const controller = GameController::Get(event);
	if (controller != NULL && controller->ProcessAxisMotion(event)) {
		ScaleJoysticks();
		return true;
	}
#endif
	Joystick *const joystick = Joystick::Get(event);
	if (joystick != NULL && joystick->ProcessAxisMotion(event)) {
		ScaleJoysticks();
		return true;
	}
#if HAS_KBCTRL == 1
	if (ProcessKbCtrlAxisMotion(event))
		return true;
#endif
	return SimulateRightStickWithDpad(event, ctrl_event);
}