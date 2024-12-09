static
  UImageFormat
  pivot_in_format(UImageFormat f, UImageFormat target)
  {
    switch (f)
    {
    case IMAGE_GREY4:
    case IMAGE_GREY8:
    case IMAGE_PPM:
    case IMAGE_RGB:
      return IMAGE_RGB;

    case IMAGE_JPEG:
      if (target == IMAGE_RGB)
        return IMAGE_RGB;
      else
        return IMAGE_YCbCr;

    case IMAGE_NV12:
    case IMAGE_YCbCr:
    case IMAGE_YUV411_PLANAR:
    case IMAGE_YUV420_PLANAR:
    case IMAGE_YUV422:
      return IMAGE_YCbCr;

    case IMAGE_UNKNOWN:
      ;
    }
    return IMAGE_UNKNOWN;
  }