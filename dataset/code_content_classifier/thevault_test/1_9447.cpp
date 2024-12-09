RenderTarget RenderTarget::ScreenRenderTarget(Renderer& renderer) {
  RenderTarget screen_render_target = RenderTarget();
  screen_render_target.framebuffer_id_ = InvalidBufferHandle();
  screen_render_target.rendered_texture_id_ = InvalidTextureHandle();
  screen_render_target.depth_buffer_id_ = InvalidBufferHandle();
  mathfu::vec2i window_size = renderer.environment().GetViewportSize();
  screen_render_target.dimensions_ = window_size;
  screen_render_target.initialized_ = true;
  return screen_render_target;
}