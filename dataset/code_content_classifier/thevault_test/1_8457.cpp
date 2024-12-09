void glut_resize(int32_t _width, int32_t _height) {
  window_width_ = _width;
  window_height_ = _height;
  camera_->updateProjection(_width, _height);
  ImGui_ImplFreeGLUT_ReshapeFunc(_width, _height);
}