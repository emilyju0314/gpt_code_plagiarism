bool ts::SignalizationDemux::addTableId(TID tid)
{
    // Do not repeat already filtered table ids.
    if (hasTableId(tid)) {
        return true;
    }

    // Configure the demux according to the table id.
    switch (tid) {
        case TID_PAT: {
            _demux.addPID(PID_PAT);
            // The current PAT may have already been received without notification to the application.
            if (_last_pat.isValid() && _handler != nullptr && !_last_pat_handled) {
                _last_pat_handled = true;
                _handler->handlePAT(_last_pat, PID_PAT);
            }
            break;
        }
        case TID_CAT: {
            _demux.addPID(PID_CAT);
            break;
        }
        case TID_PMT: {
            // We need the PAT to get PMT PID's.
            _demux.addPID(PID_PAT);
            // If a PAT is known, add all PMT PID's.
            if (_last_pat.isValid()) {
                for (auto it = _last_pat.pmts.begin(); it != _last_pat.pmts.end(); ++it) {
                    _demux.addPID(it->second);
                }
            }
            break;
        }
        case TID_TSDT: {
            _demux.addPID(PID_TSDT);
            break;
        }
        case TID_NIT_ACT:
        case TID_NIT_OTH:  {
            // We need the PAT to get the NIT PID.
            _demux.addPID(PID_PAT);
            _demux.addPID(nitPID());
            break;
        }
        case TID_SDT_ACT:
        case TID_SDT_OTH:
        case TID_BAT: {
            // SDT and BAT share the same PID.
            _demux.addPID(PID_SDT);
            break;
        }
        case TID_RST: {
            _demux.addPID(PID_RST);
            break;
        }
        case TID_TDT:
        case TID_TOT: {
            // TDT and TOT share the same PID.
            _demux.addPID(PID_TDT);
            break;
        }
        case TID_MGT:
        case TID_CVCT:
        case TID_TVCT:
        case TID_RRT:
        case TID_STT: {
            // With ATSC, the PSIP base PID contains almost all tables.
            _demux.addPID(PID_PSIP);
            break;
        }
        default: {
            // Unsupported table id.
            return false;
        }
    }

    // Add the table id.
    _tids.insert(tid);
    return true;
}