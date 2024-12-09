void _init_element_buffer(
      gl_element_buffer& buf, int n, int nc, const int* values, bool dynamic) {
    buf._num = n;
    buf._ncomp = nc;
    assert(gl_check_error());
    buf._bid = (GLuint)0;
    glGenBuffers(1, &buf._bid);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buf._bid);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, buf._num * buf._ncomp * sizeof(int),
                 values, (dynamic) ? GL_DYNAMIC_DRAW : GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    assert(gl_check_error());
  }