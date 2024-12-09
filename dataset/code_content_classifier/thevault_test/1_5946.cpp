static
  int
  format(const std::string& s)
  {
    switch (s[0])
    {
    case 'r': return urbi::IMAGE_RGB;
    case 'y': return urbi::IMAGE_YCbCr;
    case 'p': return urbi::IMAGE_PPM;
    case 'j': return urbi::IMAGE_JPEG;
    default:
      std::cerr << program_name() << ": invalid format: "
                << s << std::endl
                << libport::exit(EX_USAGE);
    }
  }