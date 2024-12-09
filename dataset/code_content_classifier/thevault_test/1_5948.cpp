static
  int
  convert_jpeg_to(const byte* source, size_t sourcelen,
                  UImageFormat dest_format,
                  byte** dest, size_t& size, size_t& w, size_t& h)
  {
    aver(dest_format == IMAGE_RGB || dest_format == IMAGE_YCbCr,
         dest_format);

    if (!dest)
      return 0;

    size_t sz;
    void *destination = read_jpeg((const char*) source, sourcelen,
                                  dest_format == IMAGE_RGB, sz, w, h);
    if (!destination)
    {
      size = 0;
      return 0;
    }
    if (!*dest)
    {
      *dest = (byte*) destination;
      size = sz;
      return 1;
    }
    size_t cplen = std::min(sz, size);
    memcpy(*dest, destination, cplen);
    free(destination);
    size = sz;
    return 1;
  }