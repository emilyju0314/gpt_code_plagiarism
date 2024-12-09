void PointerDelegate::WatchLoop(
    std::function<void(std::vector<flutter::PointerData>)> callback) {
  FML_LOG(INFO) << "Flutter - PointerDelegate started.";
  if (touch_responder_) {
    FML_LOG(ERROR) << "PointerDelegate::WatchLoop() must be called once.";
    return;
  }

  touch_responder_ = [this, callback](std::vector<fup_TouchEvent> events) {
    TRACE_EVENT0("flutter", "PointerDelegate::TouchHandler");
    FML_DCHECK(touch_responses_.empty()) << "precondition";
    std::vector<flutter::PointerData> to_client;
    for (const fup_TouchEvent& event : events) {
      IssueTouchTraceEvent(event);
      fup_TouchResponse
          response;  // Response per event, matched on event's index.
      if (event.has_view_parameters()) {
        touch_view_parameters_ = std::move(event.view_parameters());
      }
      if (HasValidatedTouchSample(event)) {
        const auto& sample = event.pointer_sample();
        const auto& ixn = sample.interaction();
        if (sample.phase() == fup_EventPhase::ADD &&
            !event.has_interaction_result()) {
          touch_buffer_.emplace(ixn, std::vector<flutter::PointerData>());
        }

        FML_DCHECK(touch_view_parameters_.has_value()) << "API guarantee";
        auto events = CreateTouchDraft(event, touch_view_parameters_.value());
        if (touch_buffer_.count(ixn) > 0) {
          InsertIntoBuffer(std::move(events), &touch_buffer_[ixn]);
        } else {
          InsertIntoBuffer(std::move(events), &to_client);
        }
        // For this simple client, always claim we want the gesture.
        response.set_response_type(fup_TouchResponseType::YES);
      }
      if (event.has_interaction_result()) {
        const auto& result = event.interaction_result();
        const auto& ixn = result.interaction;
        if (result.status == fup_TouchIxnStatus::GRANTED &&
            touch_buffer_.count(ixn) > 0) {
          FML_DCHECK(to_client.empty()) << "invariant";
          to_client.insert(to_client.end(), touch_buffer_[ixn].begin(),
                           touch_buffer_[ixn].end());
        }
        touch_buffer_.erase(ixn);  // Result seen, delete the buffer.
      }
      touch_responses_.push_back(std::move(response));
    }
    callback(std::move(to_client));  // Notify client of touch events, if any.

    touch_source_->Watch(std::move(touch_responses_),
                         /*copy*/ touch_responder_);
    touch_responses_.clear();
  };

  mouse_responder_ = [this, callback](std::vector<fup_MouseEvent> events) {
    TRACE_EVENT0("flutter", "PointerDelegate::MouseHandler");
    std::vector<flutter::PointerData> to_client;
    for (fup_MouseEvent& event : events) {
      IssueMouseTraceEvent(event);
      if (event.has_device_info()) {
        const auto& id = event.device_info().id();
        mouse_device_info_[id] = std::move(*event.mutable_device_info());
      }
      if (event.has_view_parameters()) {
        mouse_view_parameters_ = std::move(event.view_parameters());
      }
      if (HasValidatedMouseSample(event)) {
        const auto& sample = event.pointer_sample();
        const auto& id = sample.device_id();
        const bool any_button_down = sample.has_pressed_buttons();
        FML_DCHECK(mouse_view_parameters_.has_value()) << "API guarantee";
        FML_DCHECK(mouse_device_info_.count(id) > 0) << "API guarantee";

        const auto phase = ComputePhase(any_button_down, mouse_down_, id);
        flutter::PointerData data =
            CreateMouseDraft(event, phase, mouse_view_parameters_.value(),
                             mouse_device_info_[id]);
        to_client.emplace_back(std::move(data));
      }
    }
    callback(std::move(to_client));
    mouse_source_->Watch(/*copy*/ mouse_responder_);
  };

  // Start watching both channels.
  touch_source_->Watch(std::move(touch_responses_), /*copy*/ touch_responder_);
  touch_responses_.clear();
  mouse_source_->Watch(/*copy*/ mouse_responder_);
}