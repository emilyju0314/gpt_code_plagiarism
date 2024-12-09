void ts::SignalizationDemux::removeAllServiceIds()
{
    // If a PAT is known, remove all PMT PID's.
    // If all PMT's are still monitored, don't change anything.
    if (_last_pat.isValid() && !hasTableId(TID_PMT)) {
        for (auto it = _last_pat.pmts.begin(); it != _last_pat.pmts.end(); ++it) {
            _demux.removePID(it->second);
        }
    }

    // Forget all service ids.
    _service_ids.clear();
}