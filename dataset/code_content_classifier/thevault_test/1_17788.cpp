flutter::PointerData CreateMouseDraft(const fup_MouseEvent& event,
                                      const flutter::PointerData::Change phase,
                                      const fup_ViewParameters& view_parameters,
                                      const fup_MouseDeviceInfo& device_info) {
  FML_DCHECK(HasValidatedMouseSample(event)) << "precondition";
  const auto& sample = event.pointer_sample();

  flutter::PointerData ptr;
  ptr.Clear();
  ptr.time_stamp = event.timestamp() / 1000;  // in microseconds
  ptr.change = phase;
  ptr.kind = flutter::PointerData::DeviceKind::kMouse;
  ptr.device = sample.device_id();

  // View parameters can change mid-interaction; apply transform on the fly.
  auto logical =
      ViewportToViewCoordinates(sample.position_in_viewport(),
                                view_parameters.viewport_to_view_transform);
  ptr.physical_x = logical[0];  // Not yet physical; adjusted in PlatformView.
  ptr.physical_y = logical[1];  // Not yet physical; adjusted in PlatformView.

  // Ensure gesture recognition: DOWN starts in the logical view space.
  if (ptr.change == flutter::PointerData::Change::kDown) {
    auto [x, y] =
        ClampToViewSpace(ptr.physical_x, ptr.physical_y, view_parameters);
    ptr.physical_x = x;
    ptr.physical_y = y;
  }

  if (sample.has_pressed_buttons()) {
    int64_t flutter_buttons = 0;
    const auto& pressed = sample.pressed_buttons();
    for (size_t idx = 0; idx < pressed.size(); ++idx) {
      const uint8_t button_id = pressed[idx];
      FML_DCHECK(device_info.has_buttons()) << "API guarantee";
      // Priority 0 maps to kPrimaryButton, and so on.
      for (uint8_t prio = 0; prio < device_info.buttons().size(); ++prio) {
        if (button_id == device_info.buttons()[prio]) {
          flutter_buttons |= (1 << prio);
        }
      }
    }
    FML_DCHECK(flutter_buttons != 0);
    ptr.buttons = flutter_buttons;
  }

  // Fuchsia currently provides scroll data in "ticks", not physical pixels.
  // However, Flutter expects scroll data in physical pixels. To compensate for
  // lack of guidance, we make up a "reasonable amount".
  // TODO(fxbug.dev/85388): Replace with physical pixel scroll.
  const int kScrollOffsetMultiplier = 20;

  if (sample.has_scroll_v()) {
    ptr.signal_kind = flutter::PointerData::SignalKind::kScroll;
    double dy = -sample.scroll_v() * kScrollOffsetMultiplier;  // logical amount
    ptr.scroll_delta_y = dy;  // Not yet physical; adjusted in Platform View.
  }

  if (sample.has_scroll_h()) {
    ptr.signal_kind = flutter::PointerData::SignalKind::kScroll;
    double dx = sample.scroll_h() * kScrollOffsetMultiplier;  // logical amount
    ptr.scroll_delta_x = dx;  // Not yet physical; adjusted in Platform View.
  }

  return ptr;
}