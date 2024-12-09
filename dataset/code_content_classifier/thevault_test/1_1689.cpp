void
dumb_cache_manager::update_stream(const etix::cameradar::stream_model& newmodel) {
    std::lock_guard<std::mutex> lock(m);
    for (auto& stream : this->streams) {
        if (stream.address == newmodel.address && stream.port == newmodel.port) {
            stream = newmodel;
        }
    }
}