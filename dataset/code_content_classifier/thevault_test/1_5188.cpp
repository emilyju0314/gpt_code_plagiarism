void ts::PESPlugin::handlePESPacket(PESDemux&, const PESPacket& pkt)
{
    std::ostream& out(_outfile.is_open() ? _outfile : std::cout);

    // Skip PES packets without appropriate payload size
    if (int(pkt.payloadSize()) < _min_payload || (_max_payload >= 0 && int(pkt.payloadSize()) > _max_payload)) {
        return;
    }

    // Report packet description
    if (_trace_packets) {
        UString line(UString::Format(u"PID 0x%X, stream_id %s, size: %d bytes (header: %d, payload: %d)",
                                     {pkt.getSourcePID(),
                                      names::StreamId(pkt.getStreamId(), names::FIRST),
                                      pkt.size(), pkt.headerSize(), pkt.payloadSize()}));
        const size_t spurious = pkt.spuriousDataSize();
        if (spurious > 0) {
            line.append(UString::Format(u", %d spurious trailing bytes", {spurious}));
        }
        out << "* " << line << std::endl;
        if (lastDump(out)) {
            return;
        }
    }

    // Report TS packet index
    if (_trace_packet_index) {
        out << UString::Format(u"  First TS packet: %'d, last: %'d", {pkt.getFirstTSPacketIndex(), pkt.getLastTSPacketIndex()}) << std::endl;
    }

    // Report PES header
    if (_dump_pes_header) {
        size_t size = pkt.headerSize();
        out << "  PES header";
        if (_max_dump_size > 0 && size > _max_dump_size) {
            size = _max_dump_size;
            out << " (truncated)";
        }
        out << ":" << std::endl << UString::Dump(pkt.header(), size, _hexa_flags, 4, _hexa_bpl);
        if (lastDump (out)) {
            return;
        }
    }

    // Check that video packets start with either 00 00 01 (ISO 11172-2, MPEG-1, or ISO 13818-2, MPEG-2)
    // or 00 00 00 .. 01 (ISO 14496-10, MPEG-4 AVC). Don't know how ISO 14496-2 (MPEG-4 video) should start.
    if (IsVideoSID(pkt.getStreamId()) && !pkt.isMPEG2Video() && !pkt.isAVC()) {
        out << UString::Format(u"WARNING: PID 0x%X, invalid start of video PES payload: ", {pkt.getSourcePID()})
            << UString::Dump(pkt.payload(), std::min<size_t> (8, pkt.payloadSize()), UString::SINGLE_LINE)
            << std::endl;
    }

    // Report PES payload
    if (_dump_pes_payload) {
        size_t size = pkt.payloadSize();
        out << "  PES payload";
        if (_max_dump_size > 0 && size > _max_dump_size) {
            size = _max_dump_size;
            out << " (truncated)";
        }
        out << ":" << std::endl << UString::Dump(pkt.payload(), size, _hexa_flags | UString::ASCII, 4, _hexa_bpl);
        if (lastDump(out)) {
            return;
        }
    }
}