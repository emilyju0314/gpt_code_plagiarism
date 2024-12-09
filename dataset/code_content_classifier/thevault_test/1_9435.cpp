void HeadMountedDisplayRenderEnd(Renderer* renderer, bool use_undistortion) {
  // Reset the screen, and finish
  Viewport viewport(mathfu::kZeros2i, renderer->GetViewportSize());
  renderer->SetViewport(viewport);
  if (use_undistortion) {
    FinishUndistortFramebuffer();
    // Verify that the Cardboard API has not changed the rendering state.
    // If we hit this assert, we'll have to set the appropriate state to
    // `unknown` here.
    assert(ValidateRenderState(renderer->GetRenderState()));
    renderer->SetBlendMode(kBlendModeOff);
  }
}