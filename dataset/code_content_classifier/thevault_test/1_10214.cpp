void DefaultLogger::finish() {
    // Lock the mutex to guard output writing
    std::lock_guard<std::mutex> lock(write_mutex_);

    if(!last_identifier_.empty()) {
        // Flush final line if necessary
        for(auto stream : get_streams()) {
            (*stream) << std::endl;
            (*stream).flush();
        }
    }

    last_identifier_ = "";
    last_message_ = "";

    // Enable cursor again if stream supports it
    for(auto stream : get_streams()) {
        if(is_terminal(*stream)) {
            (*stream) << "\x1B[?25h";
            (*stream).flush();
        }
    }

    get_streams().clear();
}