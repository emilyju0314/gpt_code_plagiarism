rendermodel_manager::rendermodel_manager(openvr::system & tracker)
    : tracker(tracker)
    , known_ready(false)
    , invalidate_models_on_model_skin_settings_have_changed(tracker.on_model_skin_settings_have_changed.connect([&] { 
        log("rendermodel")->info("model skin settings have changed");
        invalidate();
      }))
    , poll_on_tracked_device_activated(tracker.on_tracked_device_activated.connect([&] { 
        log("rendermodel")->info("tracked device activated");
        known_ready = false; poll();
      }))
    , shader("rendermodel")
    , vrrm(vr::VRRenderModels()) {
    glUniformBlockBinding(shader.programId, 0, 0);
  }