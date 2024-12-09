static bool CheckProgram(GLuint handle, const char* desc) {
  GLint status = 0, log_length = 0;
  glGetProgramiv(handle, GL_LINK_STATUS, &status);
  glGetProgramiv(handle, GL_INFO_LOG_LENGTH, &log_length);
  if (log_length > 1) {
    ImVector<char> buf;
    buf.resize(static_cast<int>(log_length + 1));
    glGetProgramInfoLog(handle, log_length, NULL, static_cast<GLchar*>(buf.begin()));
    LOG("Log from shader program linking: %s", buf.begin());
  }
  if (static_cast<GLboolean>(status) == GL_FALSE) {
    FATAL("Orbit_ImGui_CreateDeviceObjects: failed to link %s!", desc);
  }
  return static_cast<GLboolean>(status) == GL_TRUE;
}