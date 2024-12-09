void ts::PESDemux::feedPacket(const TSPacket& pkt)
{
    // Feed the section demux to get the PAT and PMT's.
    _section_demux.feedPacket(pkt);

    // Process PES data on filtered PID's.
    if (_pid_filter[pkt.getPID()]) {
        processPacket(pkt);
    }

    // Invoke super class for its own processing.
    SuperClass::feedPacket(pkt);
}