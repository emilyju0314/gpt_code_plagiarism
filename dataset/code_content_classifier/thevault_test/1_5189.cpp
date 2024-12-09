void ts::PESPlugin::handleVideoStartCode(PESDemux&, const PESPacket& pkt, uint8_t start_code, size_t offset, size_t size)
{
    if (!_dump_start_code) {
        return;
    }

    std::ostream& out(_outfile.is_open() ? _outfile : std::cout);

    out << UString::Format(u"* PID 0x%X, start code %s, offset in PES payload: %d, size: %d bytes", {pkt.getSourcePID(), names::PESStartCode(start_code, names::FIRST), offset, size})
        << std::endl;

    size_t dsize = size;
    out << "  MPEG-1/2 video unit";
    if (_max_dump_size > 0 && dsize > _max_dump_size) {
        dsize = _max_dump_size;
        out << " (truncated)";
    }
    out << ":" << std::endl << UString::Dump(pkt.payload() + offset, dsize, _hexa_flags, 4, _hexa_bpl);

    lastDump(out);
}