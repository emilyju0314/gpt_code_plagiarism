bool ts::SignalizationDemux::removeTableId(TID tid)
{
    // Do nothing if the table id was not filtered.
    if (!hasTableId(tid)) {
        return false;
    }

    // Remove the table id first.
    _tids.erase(tid);

    // Configure the demux according to the table id.
    switch (tid) {
        case TID_PAT: {
            // Stop monitoring the PAT only when there is no need to get PMT's or NIT.
            if (!hasTableId(TID_PMT) && _service_ids.empty() && !hasTableId(TID_NIT_ACT) && !hasTableId(TID_NIT_OTH)) {
                _demux.removePID(PID_PAT);
            }
            break;
        }
        case TID_CAT: {
            _demux.removePID(PID_CAT);
            break;
        }
        case TID_PMT: {
            // If a PAT is known, remove all PMT PID's which are not specifically monitored by service id.
            if (_last_pat.isValid()) {
                for (auto it = _last_pat.pmts.begin(); it != _last_pat.pmts.end(); ++it) {
                    if (!hasServiceId(it->first)) {
                        _demux.removePID(it->second);
                    }
                }
            }
            break;
        }
        case TID_TSDT: {
            _demux.removePID(PID_TSDT);
            break;
        }
        case TID_NIT_ACT:
        case TID_NIT_OTH: {
            // Remove the PID only if no type of NIT is monitored.
            if (!hasTableId(TID_NIT_ACT) && !hasTableId(TID_NIT_OTH)) {
                _demux.removePID(nitPID());
            }
            break;
        }
        case TID_SDT_ACT:
        case TID_SDT_OTH:
        case TID_BAT: {
            // SDT and BAT share the same PID. Remove the PID only if none is monitored.
            if (!hasTableId(TID_SDT_ACT) && !hasTableId(TID_SDT_OTH) && !hasTableId(TID_BAT)) {
                _demux.removePID(PID_SDT);
            }
            break;
        }
        case TID_RST: {
            _demux.removePID(PID_RST);
            break;
        }
        case TID_TDT:
        case TID_TOT: {
            // TDT and TOT share the same PID. Remove the PID only if none is monitored.
            if (!hasTableId(TID_TDT) && !hasTableId(TID_TOT)) {
                _demux.removePID(PID_TDT);
            }
            break;
        }
        case TID_MGT:
        case TID_CVCT:
        case TID_TVCT:
        case TID_RRT:
        case TID_STT: {
            // With ATSC, the PSIP base PID contains almost all tables.
            if (!hasTableId(TID_MGT) && !hasTableId(TID_CVCT) && !hasTableId(TID_TVCT) && !hasTableId(TID_RRT) && !hasTableId(TID_STT)) {
                _demux.removePID(PID_PSIP);
            }
            break;
        }
        default: {
            // Unsupported table id.
            return false;
        }
    }

    // Table id successfully removed.
    return true;
}