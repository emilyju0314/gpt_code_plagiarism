reader(std::istream &                      str,
           char const                          field_separator,
           header_kind                         header = header_kind::none,
           transparent_istream_options const & istream_options =
             transparent_istream_options{}) requires(record_kind_ == record_kind::line_and_fields) :
      stream{str, istream_options}, it{stream, field_separator}
    {
        read_header(header);
    }