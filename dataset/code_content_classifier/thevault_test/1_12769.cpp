void ts::EITGenerator::setTransportStreamId(uint16_t ts_id)
{
    _ts_id = ts_id;
    _ts_id_set = true;
    _demux.removePID(PID_PAT);
}