bool
parsing::print_detected_cameras(const std::vector<stream_model>& data) const {
    int added = 0;
    for (const auto& stream : data) {
        if (!stream.service_name.compare("rtsp") && !stream.state.compare("open")) {
            try {
                LOG_INFO_("Generated JSON Result : " + deserialize(stream).toStyledString(),
                          "print");
                added++;
            } catch (const std::runtime_error& e) {
                LOG_WARN_("Port already scanned : " + std::string(e.what()), "parsing");
                added++;
            }
        }
    }
    if (!added) {
        LOG_WARN_(
            "Mapping unsuccessful, no rtsp streams were discovered. You "
            "should try other "
            "targetworks",
            "parsing");
        return false;
    }
    LOG_INFO_("Mapping successfuly ended, " + std::to_string(added) +
                  " RTSP streams were discovered.",
              "parsing");
    (*cache)->set_streams(data);
    return true;
}