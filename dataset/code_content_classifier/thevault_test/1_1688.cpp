void
dumb_cache_manager::set_streams(std::vector<etix::cameradar::stream_model> model) {
    std::lock_guard<std::mutex> lock(m);
    this->streams = model;
}