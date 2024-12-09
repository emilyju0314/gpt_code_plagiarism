void Ensight_Stream::open(const std::string &file_name, const bool binary, const bool geom_file,
                          const bool decomposed) {
  Require(!file_name.empty());

  d_binary = binary;

  // Open the stream.
  if (decomposed) {
    if (binary)
      d_decomposed_stream = std::make_unique<rtt_c4::ofpstream>(file_name, std::ios::binary);
    else
      d_decomposed_stream = std::make_unique<rtt_c4::ofpstream>(file_name);
    // set to a generic ostream
    d_stream = &*d_decomposed_stream;
  } else {
    Insist(rtt_c4::node() == 0, "Ensight_Stream, called by nonzero rank without "
                                "the domain decomposed flag");
    if (binary)
      d_serial_stream = std::make_unique<std::ofstream>(file_name, std::ios::binary);
    else
      d_serial_stream = std::make_unique<std::ofstream>(file_name);
    // set to a generic ostream
    d_stream = &*d_serial_stream;
  }
  Check(d_stream);

  // Set up the file.

  if (binary) {
    if (geom_file)
      *this << "C Binary";
  } else {
    // set precision for ascii mode
    d_stream->precision(5);
    d_stream->setf(std::ios::scientific, std::ios::floatfield);
  }

  Ensure(d_stream->good());
}