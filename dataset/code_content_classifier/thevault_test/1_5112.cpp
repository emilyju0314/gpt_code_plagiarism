ts::PID ts::PMT::firstVideoPID() const
{
    for (auto it = streams.begin(); it != streams.end(); ++it) {
        if (it->second.isVideo()) {
            return it->first;
        }
    }
    return PID_NULL; // not found
}