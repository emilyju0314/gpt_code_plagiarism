void _init_vertex_buffer(gl_vertex_buffer& buf, int n, int nc,
                           const void* values, bool as_float, bool dynamic) {
    buf._num = n;
    buf._ncomp = nc;
    buf._float = as_float;
    assert(gl_check_error());
    buf._bid = (GLuint)0;
    glGenBuffers(1, &buf._bid);
    glBindBuffer(GL_ARRAY_BUFFER, buf._bid);
    glBufferData(GL_ARRAY_BUFFER,
                 buf._num * buf._ncomp * ((as_float) ? sizeof(float) : sizeof(int)),
                 values, (dynamic) ? GL_DYNAMIC_DRAW : GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    assert(gl_check_error());
  }