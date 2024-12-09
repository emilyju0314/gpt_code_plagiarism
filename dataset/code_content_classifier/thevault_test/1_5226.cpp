ts::VCT::ChannelList::const_iterator ts::VCT::findService(uint16_t id, bool same_ts) const
{
    for (auto it = channels.begin(); it != channels.end(); ++it) {
        if (!same_ts || it->second.channel_TSID == transport_stream_id) {
            if (id == it->second.program_number) {
                return it;
            }
        }
    }

    // Service not found
    return channels.end();
}