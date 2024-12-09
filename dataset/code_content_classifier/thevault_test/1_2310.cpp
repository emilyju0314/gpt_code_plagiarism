void InputCommandDispatcher::DispatchMouseCommand(const SendPointerInputCmd& command) {
  TRACE_DURATION("input", "dispatch_command", "command", "MouseCmd");

  const uint32_t device_id = command.pointer_event.device_id;
  const Phase pointer_phase = command.pointer_event.phase;
  const escher::vec2 pointer = PointerCoords(command.pointer_event);

  FXL_DCHECK(command.pointer_event.type == PointerEventType::MOUSE);
  FXL_DCHECK(pointer_phase != Phase::ADD && pointer_phase != Phase::REMOVE &&
             pointer_phase != Phase::HOVER)
      << "Oops, mouse device (id=" << device_id << ") had an unexpected event: " << pointer_phase;

  if (pointer_phase == Phase::DOWN) {
    GlobalId compositor_id(command_dispatcher_context()->session_id(), command.compositor_id);

    // Find top-hit target and associated properties.
    // NOTE: We may hit various mouse cursors (owned by root presenter), but |TopHitAccumulator|
    // will keep going until we find a hit with a valid owning View.
    gfx::TopHitAccumulator top_hit;
    PerformGlobalHitTest(GetLayerStack(engine_, compositor_id), pointer, &top_hit);

    ViewStack hit_view;

    if (top_hit.hit()) {
      const gfx::ViewHit& hit = *top_hit.hit();

      hit_view.stack.push_back({
          hit.view->view_ref_koid(),
          hit.view->event_reporter()->GetWeakPtr(),
          hit.transform,
      });
    }
    FXL_VLOG(1) << "View hit: " << hit_view;

    if (!hit_view.stack.empty()) {
      // Request that focus be transferred to the top view.
      RequestFocusChange(hit_view.stack[0].view_ref_koid);
    } else if (focus_chain_root() != ZX_KOID_INVALID) {
      // The mouse event stream has no designated receiver.
      // Request that focus be transferred to the root view, so that (1) the currently focused view
      // becomes unfocused, and (2) the focus chain remains under control of the root view.
      RequestFocusChange(focus_chain_root());
    }

    // Save target for consistent delivery of mouse events.
    mouse_targets_[device_id] = hit_view;
  }

  if (mouse_targets_.count(device_id) > 0 &&         // Tracking this device, and
      mouse_targets_[device_id].stack.size() > 0) {  // target view exists.
    const auto& entry = mouse_targets_[device_id].stack[0];
    PointerEvent clone;
    fidl::Clone(command.pointer_event, &clone);
    ReportPointerEvent(entry, std::move(clone));
  }

  if (pointer_phase == Phase::UP || pointer_phase == Phase::CANCEL) {
    mouse_targets_.erase(device_id);
  }

  // Deal with unlatched MOVE events.
  if (pointer_phase == Phase::MOVE && mouse_targets_.count(device_id) == 0) {
    GlobalId compositor_id(command_dispatcher_context()->session_id(), command.compositor_id);

    // Find top-hit target and send it this move event.
    // NOTE: We may hit various mouse cursors (owned by root presenter), but |TopHitAccumulator|
    // will keep going until we find a hit with a valid owning View.
    gfx::TopHitAccumulator top_hit;
    PerformGlobalHitTest(GetLayerStack(engine_, compositor_id), pointer, &top_hit);

    if (top_hit.hit()) {
      const gfx::ViewHit& hit = *top_hit.hit();

      ViewStack::Entry view_info;
      view_info.reporter = hit.view->event_reporter()->GetWeakPtr();
      view_info.transform = hit.transform;
      PointerEvent clone;
      fidl::Clone(command.pointer_event, &clone);
      ReportPointerEvent(view_info, std::move(clone));
    }
  }
}