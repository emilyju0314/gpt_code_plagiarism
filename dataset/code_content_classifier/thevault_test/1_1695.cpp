bool
thumbnail::run() const {
    std::vector<std::future<bool>> futures;
    std::vector<stream_model> streams = (*cache)->get_valid_streams();

    LOG_INFO_("Started thumbnail generation, it may take a while", "thumbnail");
    if (not streams.size()) {
        LOG_WARN_("There were no valid streams to generate thumbnails from. Cameradar will stop.",
                  "thumbnail_generation");
        return false;
    }
    int done = 0;
    for (const auto& stream : streams) {
        futures.push_back(
            std::async(std::launch::async, &thumbnail::generate_thumbnail, this, stream));
    }
    for (auto& fit : futures) {
        if (fit.get()) { ++done; }
    }
    return true;
}