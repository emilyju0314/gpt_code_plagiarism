writer_base(std::filesystem::path const & filename, format_type const & fmt, options_t const & opt = options_t{}) :
      options{opt}, stream{filename, opt.stream_options}, format{fmt}
    {
        init();
    }