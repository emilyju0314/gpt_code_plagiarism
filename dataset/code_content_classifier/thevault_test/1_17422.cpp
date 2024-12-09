explicit header(std::string_view plaintext_header)
    {
        init();

        if (plaintext_header.ends_with("\r\n"))
            plaintext_header = plaintext_header.substr(0, plaintext_header.size() - 2);
        else if (plaintext_header.ends_with("\n"))
            plaintext_header = plaintext_header.substr(0, plaintext_header.size() - 1);

        for (std::string_view const line : plaintext_header | detail::eager_split('\n'))
            parse_line(line);

        add_missing();
    }