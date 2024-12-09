void Scene::Render(GLuint color_texture, GLuint depth_texture,
                   TangoSupport_Rotation camera_to_display_rotation) {
  glViewport(0, 0, viewport_width_, viewport_height_);
  if (color_texture == 0 || depth_texture == 0) {
    return;
  }

  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
  camera_texture_drawable_.SetColorTextureId(color_texture);
  camera_texture_drawable_.SetDepthTextureId(depth_texture);
  camera_texture_drawable_.RenderImage(camera_to_display_rotation);
}