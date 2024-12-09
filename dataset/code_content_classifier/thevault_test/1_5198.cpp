void ts::SignalizationDemux::addServiceId(uint16_t sid)
{
    // Do something only when the service is not yet monitored.
    if (!hasServiceId(sid)) {

        // Remember the service id to monitor.
        _service_ids.insert(sid);

        // We need the PAT to get PMT PID's.
        _demux.addPID(PID_PAT);

        // If a PAT is known and references the service, add its PMT PID.
        if (_last_pat.isValid()) {
            const auto it(_last_pat.pmts.find(sid));
            if (it != _last_pat.pmts.end()) {
                _demux.addPID(it->second);
            }
        }
    }
}