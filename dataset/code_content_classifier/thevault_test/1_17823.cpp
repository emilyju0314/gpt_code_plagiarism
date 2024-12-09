GLint GLFilter::compileShader(GLenum target,
                              GLsizei count,
                              const GLchar** sources,
                              GLuint* shader) const {
  GLint status;

  *shader = glCreateShader(target);
  glShaderSource(*shader, count, sources, NULL);
  glCompileShader(*shader);

  GLint logLength = 0;
  glGetShaderiv(*shader, GL_INFO_LOG_LENGTH, &logLength);
  if (logLength > 0) {
    std::vector<GLchar> log(logLength);
    glGetShaderInfoLog(*shader, logLength, &logLength, &log[0]);
    gl_log(GL_ERR, "Shader compile log:\n%s", &log[0]);
  }

  glGetShaderiv(*shader, GL_COMPILE_STATUS, &status);
  if (status == 0) {
    int i;

    gl_log(GL_ERR, "Failed to compile shader:\n");
    for (i = 0; i < count; i++)
      gl_log(GL_ERR, "%s", sources[i]);
  }

  return status;
}