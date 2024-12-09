int ComputePixelSize(GLenum format, GLenum type)
{
    switch (type)
    {
      case GL_UNSIGNED_BYTE:
        switch (format)
        {
          case GL_ALPHA:           return sizeof(unsigned char);
          case GL_LUMINANCE:       return sizeof(unsigned char);
          case GL_LUMINANCE_ALPHA: return sizeof(unsigned char) * 2;
          case GL_RGB:             return sizeof(unsigned char) * 3;
          case GL_RGBA:            return sizeof(unsigned char) * 4;
          case GL_BGRA_EXT:        return sizeof(unsigned char) * 4;
          default: UNREACHABLE();
        }
        break;
      case GL_UNSIGNED_SHORT_4_4_4_4:
      case GL_UNSIGNED_SHORT_5_5_5_1:
      case GL_UNSIGNED_SHORT_5_6_5:
        return sizeof(unsigned short);
      case GL_FLOAT:
        switch (format)
        {
          case GL_ALPHA:           return sizeof(float);
          case GL_LUMINANCE:       return sizeof(float);
          case GL_LUMINANCE_ALPHA: return sizeof(float) * 2;
          case GL_RGB:             return sizeof(float) * 3;
          case GL_RGBA:            return sizeof(float) * 4;
          default: UNREACHABLE();
        }
        break;
      case GL_HALF_FLOAT_OES:
        switch (format)
        {
          case GL_ALPHA:           return sizeof(unsigned short);
          case GL_LUMINANCE:       return sizeof(unsigned short);
          case GL_LUMINANCE_ALPHA: return sizeof(unsigned short) * 2;
          case GL_RGB:             return sizeof(unsigned short) * 3;
          case GL_RGBA:            return sizeof(unsigned short) * 4;
          default: UNREACHABLE();
        }
        break;
      default: UNREACHABLE();
    }

    return 0;
}