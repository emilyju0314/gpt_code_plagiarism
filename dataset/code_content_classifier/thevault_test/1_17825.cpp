GLint GLFilter::validateProgram(GLuint program) const {
  GLint status;

  glValidateProgram(program);

  GLint logLength = 0;
  glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logLength);
  if (logLength > 0) {
    std::vector<GLchar> log(logLength);
    glGetProgramInfoLog(program, logLength, &logLength, &log[0]);
    gl_log(GL_ERR, "Program validate log:\n%s", &log[0]);
  }

  glGetProgramiv(program, GL_VALIDATE_STATUS, &status);
  if (status == 0)
    gl_log(GL_ERR, "Failed to validate program %d\n", program);

  return status;
}