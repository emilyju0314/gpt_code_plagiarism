bool Keyboard_::isKeyPressed(uint8_t k) {
  if (k <= HID_LAST_KEY) {
    uint8_t bit = 1 << (uint8_t(k) % 8);
    return !!(report_.keys[k / 8] & bit);
  }
  return false;
}