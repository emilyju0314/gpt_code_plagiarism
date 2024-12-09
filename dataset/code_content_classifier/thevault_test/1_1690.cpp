bool
dumb_cache_manager::has_changed(const etix::cameradar::stream_model& old) {
    for (const auto& stream : this->streams) {
        if (stream.address == old.address)
            if (stream.path_found != old.path_found || stream.ids_found != old.ids_found)
                return true;
    }
    return false;
}