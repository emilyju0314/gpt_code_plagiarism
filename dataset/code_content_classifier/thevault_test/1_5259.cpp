void ts::tsp::PluginExecutor::initBuffer(PacketBuffer* buffer,
                                         PacketMetadataBuffer* metadata,
                                         size_t        pkt_first,
                                         size_t        pkt_cnt,
                                         bool          input_end,
                                         bool          aborted,
                                         BitRate       bitrate)
{
    _buffer = buffer;
    _metadata = metadata;
    _pkt_first = pkt_first;
    _pkt_cnt = pkt_cnt;
    _input_end = input_end;
    _tsp_aborting = aborted;
    _bitrate = bitrate;
    _tsp_bitrate = bitrate;
}