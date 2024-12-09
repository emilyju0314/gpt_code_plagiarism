static
  UImageFormat
  pivot_out_format(UImageFormat f)
  {
    switch (f)
    {
    case IMAGE_RGB:
    case IMAGE_PPM:
    case IMAGE_GREY8:
      return IMAGE_RGB;
    case IMAGE_YCbCr:
    case IMAGE_NV12:
    case IMAGE_YUV411_PLANAR:
    case IMAGE_YUV420_PLANAR:
      return IMAGE_YCbCr;
    case IMAGE_JPEG:
      return IMAGE_JPEG;
    default:
      return IMAGE_UNKNOWN;
    }
  }