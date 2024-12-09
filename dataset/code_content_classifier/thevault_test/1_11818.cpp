void clear_program(gl_program& prog) {
    assert(gl_check_error());
    glDetachShader(prog._pid, prog._vid);
    glDeleteShader(prog._vid);
    prog._vid = 0;
    glDetachShader(prog._pid, prog._fid);
    glDeleteShader(prog._fid);
    prog._fid = 0;
    glDeleteProgram(prog._pid);
    prog._pid = 0;
    glDeleteVertexArrays(1, &prog._vao);
    prog._vao = 0;
    assert(gl_check_error());
  }