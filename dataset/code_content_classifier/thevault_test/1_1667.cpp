int Keyboard_::sendReport() {
  // If the new HID report differs from the previous one both in active modifier
  // keycodes and non-modifier keycodes, we will need to send at least one extra
  // report. First, we compare the modifiers bytes of the two reports.
  const uint8_t old_modifiers = last_report_.modifiers;
  const uint8_t new_modifiers = report_.modifiers;

  const uint8_t changed_modifiers = old_modifiers ^ new_modifiers;

  if (changed_modifiers != 0) {
    // There was at least one modifier change (toggled on or off), remove any
    // non-modifiers from the stored previous report that toggled off in the new
    // report, and send it to the host.
    bool non_modifiers_toggled_off = false;
    for (uint8_t i = 0; i < KEY_BYTES; ++i) {
      byte released_keycodes = last_report_.keys[i] & ~(report_.keys[i]);
      if (released_keycodes != 0) {
        last_report_.keys[i] &= ~released_keycodes;
        non_modifiers_toggled_off = true;
      }
    }
    if (non_modifiers_toggled_off) {
      sendReportUnchecked();
    }
    // Next, update the modifiers byte of the stored previous report, and send
    // it.
    last_report_.modifiers = new_modifiers;
    sendReportUnchecked();
  }

  // Finally, copy the new report to the previous one, and send it.
  if (memcmp(last_report_.keys, report_.keys, sizeof(report_.keys)) != 0) {
    memcpy(last_report_.keys, report_.keys, sizeof(report_.keys));
    return sendReportUnchecked();
  }
  // A note on return values: Kaleidoscope doesn't actually check the return
  // value of `sendReport()`, so this function could be changed to return
  // void. It would be nice if we could do something to recover from an error
  // here, but it's not at all clear what that should be. Also note that if the
  // extra reports above return an error, there's not much we can do to try to
  // recover. We could try to send the report again, but that would be likely to
  // fail as well.
  return -1;
}