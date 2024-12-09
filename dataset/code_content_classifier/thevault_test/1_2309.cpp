void InputCommandDispatcher::DispatchTouchCommand(const SendPointerInputCmd& command) {
  TRACE_DURATION("input", "dispatch_command", "command", "TouchCmd");
  trace_flow_id_t trace_id =
      PointerTraceHACK(command.pointer_event.radius_major, command.pointer_event.radius_minor);
  TRACE_FLOW_END("input", "dispatch_event_to_scenic", trace_id);

  const uint32_t pointer_id = command.pointer_event.pointer_id;
  const Phase pointer_phase = command.pointer_event.phase;
  const escher::vec2 pointer = PointerCoords(command.pointer_event);

  const bool a11y_enabled = ShouldForwardAccessibilityPointerEvents();

  FXL_DCHECK(command.pointer_event.type == PointerEventType::TOUCH);
  FXL_DCHECK(pointer_phase != Phase::HOVER) << "Oops, touch device had unexpected HOVER event.";

  if (pointer_phase == Phase::ADD) {
    GlobalId compositor_id(command_dispatcher_context()->session_id(), command.compositor_id);

    gfx::SessionHitAccumulator accumulator;
    PerformGlobalHitTest(GetLayerStack(engine_, compositor_id), pointer, &accumulator);
    const auto& hits = accumulator.hits();

    // Find input targets.  Honor the "input masking" view property.
    ViewStack hit_views;
    {
      // Find the transform (input -> view coordinates) for each hit and fill out hit_views.
      for (const gfx::ViewHit& hit : hits) {
        hit_views.stack.push_back({
            hit.view->view_ref_koid(),
            hit.view->event_reporter()->GetWeakPtr(),
            hit.transform,
        });
        if (/*TODO(SCN-919): view_id may mask input */ false) {
          break;
        }
      }
    }
    FXL_VLOG(1) << "View stack of hits: " << hit_views;

    // Save targets for consistent delivery of touch events.
    touch_targets_[pointer_id] = hit_views;

    // If there is an accessibility pointer event listener enabled, an ADD event means that a new
    // pointer id stream started. Perform it unconditionally, even if the view stack is empty.
    if (a11y_enabled) {
      pointer_event_buffer_->AddStream(pointer_id);
    }
  } else if (pointer_phase == Phase::DOWN) {
    // If accessibility listener is on, focus change events must be sent only if
    // the stream is rejected. This way, this operation is deferred.
    if (!a11y_enabled) {
      if (!touch_targets_[pointer_id].stack.empty()) {
        // Request that focus be transferred to the top view.
        RequestFocusChange(touch_targets_[pointer_id].stack[0].view_ref_koid);
      } else if (focus_chain_root() != ZX_KOID_INVALID) {
        // The touch event stream has no designated receiver.
        // Request that focus be transferred to the root view, so that (1) the currently focused
        // view becomes unfocused, and (2) the focus chain remains under control of the root view.
        RequestFocusChange(focus_chain_root());
      }
    }
  }

  // Input delivery must be parallel; needed for gesture disambiguation.
  std::vector<ViewStack::Entry> deferred_event_receivers;
  for (const auto& entry : touch_targets_[pointer_id].stack) {
    if (a11y_enabled) {
      deferred_event_receivers.emplace_back(entry);
    } else {
      ReportPointerEvent(entry, command.pointer_event);
    }
    if (!parallel_dispatch_) {
      break;  // TODO(SCN-1047): Remove when gesture disambiguation is ready.
    }
  }

  FXL_DCHECK(a11y_enabled || deferred_event_receivers.empty())
      << "When a11y pointer forwarding is off, never defer events.";

  if (a11y_enabled) {
    // We handle both latched (!deferred_event_receivers.empty()) and unlatched
    // (deferred_event_receivers.empty()) touch events, for two reasons. (1) We must notify
    // accessibility about events regardless of latch, so that it has full
    //     information about a gesture stream. E.g., the gesture could start traversal in empty
    //     space before MOVE-ing onto a rect; accessibility needs both the gesture and the rect.
    // (2) We must trigger a potential focus change request, even if no view receives the triggering
    //     DOWN event, so that (a) the focused view receives an unfocus event, and (b) the focus
    //     chain gets updated and dispatched accordingly.
    //
    // NOTE: Do not rely on the latched view stack for "top hit" information; elevation can change
    // dynamically (it's only guaranteed correct for DOWN). Instead, perform an independent query
    // for "top hit".
    glm::mat4 view_transform(1.f);
    zx_koid_t view_ref_koid = ZX_KOID_INVALID;
    GlobalId compositor_id(command_dispatcher_context()->session_id(), command.compositor_id);
    gfx::LayerStackPtr layer_stack = GetLayerStack(engine_, compositor_id);
    {
      // Find top-hit target and send it to accessibility.
      // NOTE: We may hit various mouse cursors (owned by root presenter), but |TopHitAccumulator|
      // will keep going until we find a hit with a valid owning View.
      gfx::TopHitAccumulator top_hit;
      PerformGlobalHitTest(layer_stack, pointer, &top_hit);

      if (top_hit.hit()) {
        const gfx::ViewHit& hit = *top_hit.hit();

        view_transform = hit.transform;
        view_ref_koid = hit.view->view_ref_koid();
      }
    }

    const auto ndc = NormalizePointerCoords(pointer, layer_stack);
    const auto top_hit_view_local = TransformPointerCoords(pointer, view_transform);
    AccessibilityPointerEvent packet = BuildAccessibilityPointerEvent(
        command.pointer_event, ndc, top_hit_view_local, view_ref_koid);
    pointer_event_buffer_->AddEvent(
        pointer_id,
        {.event = std::move(command.pointer_event),
         .parallel_event_receivers = std::move(deferred_event_receivers)},
        std::move(packet));
  } else {
    input_system_->ReportPointerEventToPointerCaptureListener(command.pointer_event);
  }

  if (pointer_phase == Phase::REMOVE || pointer_phase == Phase::CANCEL) {
    touch_targets_.erase(pointer_id);
  }
}