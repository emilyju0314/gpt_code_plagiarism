void ts::EITProcessor::renameTS(uint16_t old_ts_id, uint16_t new_ts_id)
{
    Service old_srv, new_srv;
    old_srv.setTSId(old_ts_id);
    new_srv.setTSId(new_ts_id);
    _renamed.push_back(std::make_pair(old_srv, new_srv));
}