void HeadMountedDisplayRenderStart(
    const HeadMountedDisplayInput& head_mounted_display_input,
    Renderer* renderer, const mathfu::vec4& clear_color, bool use_undistortion,
    HeadMountedDisplayViewSettings* view_settings) {
  if (use_undistortion) {
    BeginUndistortFramebuffer();
    // Verify that the Cardboard API has not changed the rendering state.
    // If we hit this assert, we'll have to set the appropriate state to
    // `unknown` here.
    assert(ValidateRenderState(renderer->GetRenderState()));
  }
  renderer->ClearFrameBuffer(clear_color);
  renderer->set_color(mathfu::kOnes4f);
  renderer->SetDepthFunction(fplbase::kDepthFunctionLess);

  const mathfu::vec2i viewport_size = renderer->GetViewportSize();
  int window_width = viewport_size.x;
  int window_height = viewport_size.y;
  int half_width = window_width / 2;
  // Calculate settings for each viewport.
  mathfu::vec4i* viewport_extents = view_settings->viewport_extents;
  mathfu::mat4* viewport_transforms = view_settings->viewport_transforms;
  viewport_extents[0] = mathfu::vec4i(0, 0, half_width, window_height);
  viewport_extents[1] = mathfu::vec4i(half_width, 0, half_width, window_height);
  viewport_transforms[0] = head_mounted_display_input.left_eye_transform();
  viewport_transforms[1] = head_mounted_display_input.right_eye_transform();
}