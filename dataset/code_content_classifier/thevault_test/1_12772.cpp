void ts::EITGenerator::loadEvents(const Section& section)
{
    // Filter the right EIT's.
    const TID tid = section.tableId();
    if (!section.isValid() || !EIT::IsEIT(tid) || section.payloadSize() < EIT::EIT_PAYLOAD_FIXED_SIZE) {
        return;
    }

    // If the TS is not yet known, we cannot sort actual and other EIT's.
    // If the incoming EIT is an actual one, use its TS id as current TS id.
    const ServiceIdTriplet srv(EIT::GetService(section));
    if (!_ts_id_set && EIT::IsActual(tid)) {
        setTransportStreamId(srv.transport_stream_id);
    }
    if (!_ts_id_set || ((_options & EIT_ACTUAL) == 0 && srv.transport_stream_id == _ts_id) || ((_options & EIT_OTHER) == 0 && srv.transport_stream_id != _ts_id)) {
        return;
    }



    //@@@
}