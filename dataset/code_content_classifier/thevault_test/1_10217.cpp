void DefaultLogger::addStream(std::ostream& stream) {
    // Disable cursor if stream supports it
    if(is_terminal(stream)) {
        stream << "\x1B[?25l";
    }

    get_streams().push_back(&stream);
}