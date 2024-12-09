void Keyboard::ProcessInput(hid_keys_t state) {
  // Process the pressed keys.
  uint8_t keycode;
  hid_keys_t keys;
  hid_kbd_pressed_keys(&previous_state_, &state, &keys);
  hid_for_every_key(&keys, keycode) {
    if (keycode == HID_USAGE_KEY_ERROR_ROLLOVER) {
      return;
    }
    modifiers_ |= modifiers_from_keycode(keycode);
    if (keycode == HID_USAGE_KEY_CAPSLOCK) {
      modifiers_ ^= MOD_CAPSLOCK;
      SetCapsLockLed(modifiers_ & MOD_CAPSLOCK);
    }

    if (repeat_enabled_ && !keycode_is_modifier(keycode)) {
      is_repeating_ = true;
      repeating_key_ = keycode;
      repeat_interval_ = kLowRepeatKeyFreq;
      timer_.cancel();
      timer_.set(zx::deadline_after(repeat_interval_), kSlackDuration);
    }
    handler_(keycode, modifiers_);
  }

  // Process the released keys.
  hid_kbd_released_keys(&previous_state_, &state, &keys);
  hid_for_every_key(&keys, keycode) {
    modifiers_ &= ~modifiers_from_keycode(keycode);

    if (repeat_enabled_ && is_repeating_ && (repeating_key_ == keycode)) {
      is_repeating_ = false;
      repeating_key_ = 0;
      timer_.cancel();
    }
  }

  // Store the previous state.
  previous_state_ = state;
}