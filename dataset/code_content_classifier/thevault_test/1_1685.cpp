bool
creds_attack::run() const {
    std::vector<std::future<bool>> futures;

    LOG_INFO_(
        "Beginning attack of the credentials , it may "
        "take a while.",
        "creds_attack");
    std::vector<etix::cameradar::stream_model> streams = (*cache)->get_streams();
    LOG_DEBUG_("Found " + std::to_string(streams.size()) + " streams in the cache", "creds_attack");
    size_t found = 0;
    for (const auto& stream : streams) {
        if (signal_handler::instance().should_stop() != etix::cameradar::stop_priority::running)
            break;
        if ((found < streams.size()) && ids_already_found(streams, stream)) {
            LOG_INFO_(stream.address +
                          " : This camera's ids were already discovered in "
                          "the database. Skipping to "
                          "the next camera.",
                      "creds_attack");
            ++found;
        } else {
            futures.push_back(
                std::async(std::launch::async, &creds_attack::attack_camera_creds, this, stream));
        }
    }
    for (auto& fit : futures) {
        if (fit.get()) { ++found; }
    }
    if (!found) {
        LOG_WARN_(no_ids_warning_, "creds_attack");
        return false;
    } else
        LOG_INFO_("Found " + std::to_string(found) + " ids for " + std::to_string(streams.size()) +
                      " cameras",
                  "creds_attack");
    return true;
}