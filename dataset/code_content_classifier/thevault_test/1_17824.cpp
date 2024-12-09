GLint GLFilter::linkProgram(GLuint program) const {
  GLint status;

  glLinkProgram(program);

  GLint logLength = 0;
  glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logLength);
  if (logLength > 0) {
    std::vector<GLchar> log(logLength);
    glGetProgramInfoLog(program, logLength, &logLength, &log[0]);
    gl_log(GL_ERR, "Program link log:\n%s", &log[0]);
  }

  glGetProgramiv(program, GL_LINK_STATUS, &status);
  if (status == 0)
    gl_log(GL_ERR, "Failed to link program %d\n", program);

  return status;
}