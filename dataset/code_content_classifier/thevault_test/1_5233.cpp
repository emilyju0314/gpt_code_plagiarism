void ts::TablesLogger::feedPacket(const TSPacket& pkt)
{
    if (!completed()) {
        _demux.feedPacket(pkt);
        _cas_mapper.feedPacket(pkt);
        _packet_count++;
    }
}