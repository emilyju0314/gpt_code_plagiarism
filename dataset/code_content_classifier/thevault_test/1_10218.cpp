std::string DefaultLogger::get_current_date() {
    // FIXME: revise this to get microseconds in a better way
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);

    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%X");

    auto seconds_from_epoch = std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch());
    auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch() - seconds_from_epoch).count();
    ss << ".";
    ss << std::setfill('0') << std::setw(3);
    ss << millis;
    return ss.str();
}