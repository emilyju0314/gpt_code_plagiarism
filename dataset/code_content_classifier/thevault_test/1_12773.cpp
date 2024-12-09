void ts::EITGenerator::handleSection(SectionDemux& demux, const Section& section)
{
    if (section.tableId() == TID_PAT && !_ts_id_set) {
        // A PAT section is used to define the transport stream id if not already known.
        setTransportStreamId(section.tableIdExtension());
    }
    else if (EIT::IsEIT(section.tableId()) && (_options & EIT_INPUT) != 0) {
        // Use input EIT's as EPG data when specified in the generation options.
        loadEvents(section);
    }
}