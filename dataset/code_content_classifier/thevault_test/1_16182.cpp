ParametersConfiguration(
            const std::vector<std::string> &arguments,
            const std::string &missing_error,
            const std::string &expected)
    {
        arguments_ = arguments;
        missing_error_ = missing_error;
        expected_ = expected;
    }