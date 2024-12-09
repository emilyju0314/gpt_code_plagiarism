bool ts::EITProcessor::Match(const Service& srv, uint16_t srv_id, uint16_t ts_id, uint16_t net_id)
{
    return (srv.hasId() || srv.hasTSId()) &&
        (!srv.hasId() || srv.hasId(srv_id)) &&
        (!srv.hasTSId() || srv.hasTSId(ts_id)) &&
        (!srv.hasONId() || srv.hasONId(net_id));
}