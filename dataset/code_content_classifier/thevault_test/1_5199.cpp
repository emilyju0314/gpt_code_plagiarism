void ts::SignalizationDemux::removeServiceId(uint16_t sid)
{
    // Do something only when the service is currently monitored.
    if (hasServiceId(sid)) {

        // Forget the service id to monitor.
        _service_ids.erase(sid);

        // If a PAT is known and references the service, remove its PMT PID.
        // If all PMT's are still monitored, don't change anything.
        if (_last_pat.isValid() && !hasTableId(TID_PMT)) {
            const auto it(_last_pat.pmts.find(sid));
            if (it != _last_pat.pmts.end()) {
                _demux.removePID(it->second);
            }
        }
    }
}