bool CheckTextureFormatType(GLenum format, GLenum type)
{
    switch (type)
    {
      case GL_UNSIGNED_BYTE:
        switch (format)
        {
          case GL_RGBA:
          case GL_BGRA_EXT:
          case GL_RGB:
          case GL_ALPHA:
          case GL_LUMINANCE:
          case GL_LUMINANCE_ALPHA:
            return true;

          default:
            return false;
        }

      case GL_FLOAT:
      case GL_HALF_FLOAT_OES:
        switch (format)
        {
          case GL_RGBA:
          case GL_RGB:
          case GL_ALPHA:
          case GL_LUMINANCE:
          case GL_LUMINANCE_ALPHA:
            return true;

          default:
            return false;
        }

      case GL_UNSIGNED_SHORT_4_4_4_4:
      case GL_UNSIGNED_SHORT_5_5_5_1:
        return (format == GL_RGBA);

      case GL_UNSIGNED_SHORT_5_6_5:
        return (format == GL_RGB);

      default:
        return false;
    }
}