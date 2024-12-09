LogFormat DefaultLogger::getFormatFromString(const std::string& format) {
    if(format == "SHORT") {
        return LogFormat::SHORT;
    }
    if(format == "DEFAULT") {
        return LogFormat::DEFAULT;
    }
    if(format == "LONG") {
        return LogFormat::LONG;
    }

    throw std::invalid_argument("unknown log format");
}