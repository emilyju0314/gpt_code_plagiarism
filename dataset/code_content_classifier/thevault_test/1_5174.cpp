void ts::EITProcessor::removeTS(uint16_t ts_id)
{
    Service srv;
    srv.setTSId(ts_id);
    _removed.push_back(srv);
}