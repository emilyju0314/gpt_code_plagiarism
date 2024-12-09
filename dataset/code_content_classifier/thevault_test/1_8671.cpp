bool SetDirectInputDeadZone(IDirectInputDevice8* gamepad,
                            int deadzone) {
  DIPROPDWORD prop;
  prop.diph.dwSize = sizeof(DIPROPDWORD);
  prop.diph.dwHeaderSize = sizeof(DIPROPHEADER);
  prop.diph.dwObj = 0;
  prop.diph.dwHow = DIPH_DEVICE;
  prop.dwData = deadzone;
  return SUCCEEDED(gamepad->SetProperty(DIPROP_DEADZONE, &prop.diph));
}