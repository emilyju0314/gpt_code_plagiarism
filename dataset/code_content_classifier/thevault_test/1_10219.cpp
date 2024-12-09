bool DefaultLogger::is_terminal(std::ostream& stream) {
    if(&std::cout == &stream) {
        return static_cast<bool>(isatty(fileno(stdout)));
    }
    if(&std::cerr == &stream) {
        return static_cast<bool>(isatty(fileno(stderr)));
    }

    return false;
}