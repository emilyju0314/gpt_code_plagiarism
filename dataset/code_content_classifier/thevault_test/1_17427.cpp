writer(std::ostream &                      str,
           char const                          field_separator,
           transparent_ostream_options const & ostream_options =
             transparent_ostream_options{}) requires(record_kind_ == record_kind::line_and_fields) :
      stream{str, ostream_options}, it{stream, field_separator}
    {}