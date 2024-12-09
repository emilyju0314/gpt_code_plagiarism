void ts::PESDemux::handleTable(SectionDemux& demux, const BinaryTable& table)
{
    switch (table.tableId()) {
        case TID_PAT: {
            // Got a PAT, add all PMT PID's to section demux.
            const PAT pat(_duck, table);
            if (pat.isValid()) {
                for (auto it = pat.pmts.begin(); it != pat.pmts.end(); ++it) {
                    _section_demux.addPID(it->second);
                }
            }
            break;
        }
        case TID_PMT: {
            // Got a PMT, collect all stream types.
            const PMT pmt(_duck, table);
            if (pmt.isValid()) {
                for (auto it = pmt.streams.begin(); it != pmt.streams.end(); ++it) {
                    _stream_types[it->first] = it->second.stream_type;
                }
            }
            break;
        }
        default: {
            // Nothing to do.
            break;
        }
    }
}