gl_program make_program(const string& vertex, const string& fragment) {
    auto prog = gl_program();

    assert(gl_check_error());
    glGenVertexArrays(1, &prog._vao);
    glBindVertexArray(prog._vao);
    assert(gl_check_error());

    int errflags;
    char errbuf[10000];

    // create vertex
    prog._vid = glCreateShader(GL_VERTEX_SHADER);
    const char* vertex_str = vertex.c_str();
    glShaderSource(prog._vid, 1, &vertex_str, NULL);
    glCompileShader(prog._vid);
    glGetShaderiv(prog._vid, GL_COMPILE_STATUS, &errflags);
    if (!errflags) {
      glGetShaderInfoLog(prog._vid, 10000, 0, errbuf);
      throw runtime_error(string("shader not compiled\n\n") + errbuf);
    }
    assert(glGetError() == GL_NO_ERROR);

    // create fragment
    prog._fid = glCreateShader(GL_FRAGMENT_SHADER);
    const char* fragment_str = fragment.c_str();
    glShaderSource(prog._fid, 1, &fragment_str, NULL);
    glCompileShader(prog._fid);
    glGetShaderiv(prog._fid, GL_COMPILE_STATUS, &errflags);
    if (!errflags) {
      glGetShaderInfoLog(prog._fid, 10000, 0, errbuf);
      throw runtime_error(string("shader not compiled\n\n") + errbuf);
    }
    assert(glGetError() == GL_NO_ERROR);

    // create program
    prog._pid = glCreateProgram();
    glAttachShader(prog._pid, prog._vid);
    glAttachShader(prog._pid, prog._fid);
    glLinkProgram(prog._pid);
    glValidateProgram(prog._pid);
    glGetProgramiv(prog._pid, GL_LINK_STATUS, &errflags);
    if (!errflags) {
      glGetProgramInfoLog(prog._pid, 10000, 0, errbuf);
      throw runtime_error(string("program not linked\n\n") + errbuf);
    }
    glGetProgramiv(prog._pid, GL_VALIDATE_STATUS, &errflags);
    if (!errflags) {
      glGetProgramInfoLog(prog._pid, 10000, 0, errbuf);
      throw runtime_error(string("program not linked\n\n") + errbuf);
    }
    assert(gl_check_error());

    glBindVertexArray(0);
    assert(gl_check_error());

    return prog;
  }