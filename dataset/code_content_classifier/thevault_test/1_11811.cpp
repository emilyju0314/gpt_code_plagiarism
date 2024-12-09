void gl_enable_edges(bool enabled, float tolerance) {
    assert(gl_check_error());
    if (enabled) {
      glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
      glDepthRange(0, tolerance);
    } else {
      glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
      glDepthRange(0, 1);
    }
    assert(gl_check_error());
  }