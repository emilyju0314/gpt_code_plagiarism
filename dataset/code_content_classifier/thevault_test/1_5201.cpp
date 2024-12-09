void ts::SignalizationDemux::handleTable(SectionDemux&, const BinaryTable& table)
{
    const PID pid = table.sourcePID();
    const TID tid = table.tableId();

    // The PAT needs to be monitored outside explicit filtering.
    if (tid == TID_PAT && pid == PID_PAT) {
        const PAT pat(_duck, table);
        if (pat.isValid()) {

            // Check if all PMT's are monitored.
            const bool all_pmts = hasTableId(TID_PMT);

            // If a previous PAT was there, remove unused PMT PID's.
            if (_last_pat.isValid() && (all_pmts || !_service_ids.empty())) {
                // Loop on all previous services
                for (auto it1 = _last_pat.pmts.begin(); it1 != _last_pat.pmts.end(); ++it1) {
                    // If the service no longer exists or has changed its PMT PID, remove the previous PMT PID.
                    const auto it2(pat.pmts.find(it1->first));
                    if (it2 == pat.pmts.end() || it2->second != it1->second) {
                        _demux.removePID(it1->second);
                    }
                }
            }

            // Remember the last PAT.
            _last_pat = pat;
            _last_pat_handled = false;

            // Then, monitor new PMT PID's. Some of them may be already monitored.
            for (auto it = pat.pmts.begin(); it != pat.pmts.end(); ++it) {
                if (all_pmts || hasServiceId(it->first)) {
                    _demux.addPID(it->second);
                }
            }

            // Monitor non-standard NIT PID.
            if (hasTableId(TID_NIT_ACT) || hasTableId(TID_NIT_OTH)) {
                _demux.addPID(nitPID());
            }

            // Notify the PAT to the application.
            if (_handler != nullptr && hasTableId(TID_PAT)) {
                _last_pat_handled = true;
                _handler->handlePAT(pat, pid);
            }
        }
    }

    // Other tables have no special treatment. They are directly passed to the application.
    // PMT may be selectively filtered by service id (table id extention).
    else if (_handler != nullptr && (hasTableId(tid) || (tid == TID_PMT && hasServiceId(table.tableIdExtension())))) {
        switch (tid) {
            case TID_CAT: {
                const CAT cat(_duck, table);
                if (cat.isValid() && pid == PID_CAT) {
                    _handler->handleCAT(cat, pid);
                }
                break;
            }
            case TID_PMT: {
                const PMT pmt(_duck, table);
                if (pmt.isValid()) {
                    _handler->handlePMT(pmt, pid);
                }
                break;
            }
            case TID_TSDT: {
                const TSDT tsdt(_duck, table);
                if (tsdt.isValid() && pid == PID_TSDT) {
                    _handler->handleTSDT(tsdt, pid);
                }
                break;
            }
            case TID_NIT_ACT:
            case TID_NIT_OTH:  {
                const NIT nit(_duck, table);
                if (nit.isValid() && pid == nitPID()) {
                    _handler->handleNIT(nit, pid);
                }
                break;
            }
            case TID_SDT_ACT:
            case TID_SDT_OTH:  {
                const SDT sdt(_duck, table);
                if (sdt.isValid() && pid == PID_SDT) {
                    _handler->handleSDT(sdt, pid);
                }
                break;
            }
            case TID_BAT: {
                const BAT bat(_duck, table);
                if (bat.isValid() && pid == PID_BAT) {
                    _handler->handleBAT(bat, pid);
                }
                break;
            }
            case TID_RST: {
                const RST rst(_duck, table);
                if (rst.isValid() && pid == PID_RST) {
                    _handler->handleRST(rst, pid);
                }
                break;
            }
            case TID_TDT: {
                const TDT tdt(_duck, table);
                if (tdt.isValid() && pid == PID_TDT) {
                    _handler->handleTDT(tdt, pid);
                }
                break;
            }
            case TID_TOT: {
                const TOT tot(_duck, table);
                if (tot.isValid() && pid == PID_TOT) {
                    _handler->handleTOT(tot, pid);
                }
                break;
            }
            case TID_MGT: {
                const MGT mgt(_duck, table);
                if (mgt.isValid() && pid == PID_PSIP) {
                    _handler->handleMGT(mgt, pid);
                }
                break;
            }
            case TID_CVCT: {
                const CVCT vct(_duck, table);
                if (vct.isValid() && pid == PID_PSIP) {
                    // Call specific and generic form of VCT handler.
                    _handler->handleCVCT(vct, pid);
                    _handler->handleVCT(vct, pid);
                }
                break;
            }
            case TID_TVCT: {
                const TVCT vct(_duck, table);
                if (vct.isValid() && pid == PID_PSIP) {
                    // Call specific and generic form of VCT handler.
                    _handler->handleTVCT(vct, pid);
                    _handler->handleVCT(vct, pid);
                }
                break;
            }
            case TID_RRT: {
                const RRT rrt(_duck, table);
                if (rrt.isValid() && pid == PID_PSIP) {
                    _handler->handleRRT(rrt, pid);
                }
                break;
            }
            default: {
                // Unsupported table id or processed elsewhere (PAT, STT).
                break;
            }
        }
    }
}