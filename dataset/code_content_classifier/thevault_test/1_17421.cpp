format_output_handler(std::ostream & str, auto const & options) : base_t{str}
    {
        // extract options
        if constexpr (requires { (bool)options.write_IDX; })
            write_IDX = options.write_IDX;

        if constexpr (requires { (bool)options.windows_eol; })
            windows_eol = options.windows_eol;
    }