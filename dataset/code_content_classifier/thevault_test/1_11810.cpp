bool gl_check_error(bool print) {
    auto ok = glGetError();
    if (ok == GL_NO_ERROR) return true;
    if (!print) return false;
    switch (ok) {
      case GL_NO_ERROR: printf("GL_NO_ERROR\n"); break;
      case GL_INVALID_ENUM: printf("GL_INVALID_ENUM\n"); break;
      case GL_INVALID_VALUE: printf("GL_INVALID_VALUE\n"); break;
      case GL_INVALID_OPERATION: printf("GL_INVALID_OPERATION\n"); break;
      case GL_INVALID_FRAMEBUFFER_OPERATION:
        printf("GL_INVALID_FRAMEBUFFER_OPERATION\n");
        break;
      case GL_OUT_OF_MEMORY: printf("GL_OUT_OF_MEMORY\n"); break;
      default: printf("<UNKNOWN GL ERROR>\n"); break;
    }
    return false;
  }