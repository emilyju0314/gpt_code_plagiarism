void InputSystem::HandleGamepadEvents() {
  AndroidInputEvent event;
  pthread_mutex_lock(&android_event_mutex);
  while (unhandled_java_input_events_.size() > 0) {
    event = unhandled_java_input_events_.front();
    unhandled_java_input_events_.pop();

    Gamepad &gamepad = GetGamepad(event.device_id);
    Gamepad::GamepadInputButton button_index;

    switch (event.event_code) {
      case AKEY_EVENT_ACTION_DOWN:
        button_index = static_cast<Gamepad::GamepadInputButton>(
            Gamepad::GetGamepadCodeFromJavaKeyCode(event.control_code));
        if (button_index != Gamepad::kInvalid) {
          gamepad.GetButton(button_index).Update(true);
        }
        break;
      case AKEY_EVENT_ACTION_UP:
        button_index = static_cast<Gamepad::GamepadInputButton>(
            Gamepad::GetGamepadCodeFromJavaKeyCode(event.control_code));
        if (button_index != Gamepad::kInvalid) {
          gamepad.GetButton(button_index).Update(false);
        }
        break;
      case AMOTION_EVENT_ACTION_MOVE:
        const bool left = event.x < -kGamepadHatThreshold;
        const bool right = event.x > kGamepadHatThreshold;
        const bool up = event.y < -kGamepadHatThreshold;
        const bool down = event.y > kGamepadHatThreshold;

        gamepad.GetButton(Gamepad::kLeft).Update(left);
        gamepad.GetButton(Gamepad::kRight).Update(right);
        gamepad.GetButton(Gamepad::kUp).Update(up);
        gamepad.GetButton(Gamepad::kDown).Update(down);
        break;
    }
  }
  // Clear the queue
  std::queue<AndroidInputEvent>().swap(unhandled_java_input_events_);
  pthread_mutex_unlock(&android_event_mutex);
}