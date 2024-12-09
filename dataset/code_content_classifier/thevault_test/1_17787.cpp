std::pair<flutter::PointerData, std::optional<flutter::PointerData>>
CreateTouchDraft(const fup_TouchEvent& event,
                 const fup_ViewParameters& view_parameters) {
  FML_DCHECK(HasValidatedTouchSample(event)) << "precondition";
  const auto& sample = event.pointer_sample();
  const auto& ixn = sample.interaction();

  flutter::PointerData ptr;
  ptr.Clear();
  ptr.time_stamp = event.timestamp() / 1000;  // in microseconds
  ptr.change = GetChangeFromTouchEventPhase(sample.phase());
  ptr.kind = flutter::PointerData::DeviceKind::kTouch;
  // Load Fuchsia's pointer ID onto Flutter's |device| field, and not the
  // |pointer_identifier| field. The latter is written by
  // PointerDataPacketConverter, to track individual gesture interactions.
  ptr.device = PackFuchsiaDeviceIdAndPointerId(ixn.device_id, ixn.pointer_id);
  // View parameters can change mid-interaction; apply transform on the fly.
  auto logical =
      ViewportToViewCoordinates(sample.position_in_viewport(),
                                view_parameters.viewport_to_view_transform);
  ptr.physical_x = logical[0];  // Not yet physical; adjusted in PlatformView.
  ptr.physical_y = logical[1];  // Not yet physical; adjusted in PlatformView.

  // Match Flutter pointer's state machine with synthesized events.
  if (ptr.change == flutter::PointerData::Change::kAdd) {
    flutter::PointerData down;
    memcpy(&down, &ptr, sizeof(flutter::PointerData));
    down.change = flutter::PointerData::Change::kDown;
    {  // Ensure gesture recognition: DOWN starts in the logical view space.
      auto [x, y] =
          ClampToViewSpace(down.physical_x, down.physical_y, view_parameters);
      down.physical_x = x;
      down.physical_y = y;
    }
    return {std::move(ptr), std::move(down)};
  } else if (ptr.change == flutter::PointerData::Change::kRemove) {
    flutter::PointerData up;
    memcpy(&up, &ptr, sizeof(flutter::PointerData));
    up.change = flutter::PointerData::Change::kUp;
    return {std::move(up), std::move(ptr)};
  } else {
    return {std::move(ptr), std::nullopt};
  }
}