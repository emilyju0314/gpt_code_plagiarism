writer_base(std::ostream & str, format_type const & fmt, options_t const & opt = options_t{}) :
      options{opt}, stream{str, opt.stream_options}, format{fmt}
    {
        init();
    }