format_output_handler(std::ostream & str, auto const & options) : base_t{str}
    {
        // extract options
        if constexpr (requires { (bool)options.compress_integers; })
            compress_integers = options.compress_integers;
        if constexpr (requires { (bool)options.verify_header_types; })
            verify_header_types = options.verify_header_types;
    }