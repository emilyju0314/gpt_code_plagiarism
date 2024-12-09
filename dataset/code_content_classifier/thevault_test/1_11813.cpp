void _update_vertex_buffer(
      gl_vertex_buffer& buf, int n, int nc, const void* values, bool as_float) {
    buf._num = n;
    buf._ncomp = nc;
    buf._float = as_float;
    assert(gl_check_error());
    glBindBuffer(GL_ARRAY_BUFFER, buf._bid);
    glBufferSubData(GL_ARRAY_BUFFER, 0,
                    buf._num * buf._ncomp * ((as_float) ? sizeof(float) : sizeof(int)),
                    values);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    assert(gl_check_error());
  }