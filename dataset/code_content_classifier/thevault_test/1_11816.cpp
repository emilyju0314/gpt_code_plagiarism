void _update_element_buffer(
      gl_element_buffer& buf, int n, int nc, const int* values) {
    buf._num = n;
    buf._ncomp = nc;
    assert(gl_check_error());
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buf._bid);
    glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0,
                    buf._num * buf._ncomp * sizeof(int), values);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    assert(gl_check_error());
  }