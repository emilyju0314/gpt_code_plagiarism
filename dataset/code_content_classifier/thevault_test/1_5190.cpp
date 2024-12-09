void ts::PESPlugin::handleAVCAccessUnit(PESDemux&, const PESPacket& pkt, uint8_t nal_unit_type, size_t offset, size_t size)
{
    assert(nal_unit_type < 32);

    if (!_dump_nal_units || !_nal_unit_filter.test(nal_unit_type)) {
        return;
    }

    std::ostream& out(_outfile.is_open() ? _outfile : std::cout);

    // Hexadecimal dump
    out << UString::Format(u"* PID 0x%X, AVC access unit type %s", {pkt.getSourcePID(), names::AVCUnitType(nal_unit_type, names::FIRST)})
        << std::endl
        << UString::Format(u"  Offset in PES payload: %d, size: %d bytes", {offset, size})
        << std::endl;
    size_t dsize = size;
    out << "  AVC access unit";
    if (_max_dump_size > 0 && dsize > _max_dump_size) {
        dsize = _max_dump_size;
        out << " (truncated)";
    }
    out << ":" << std::endl << UString::Dump(pkt.payload() + offset, dsize, _hexa_flags, 4, _hexa_bpl);

    // Structured formatting if possible
    switch (nal_unit_type) {
        case AVC_AUT_SEQPARAMS:
        {
            AVCSequenceParameterSet params(pkt.payload() + offset, size);
            params.display(out, u"  ");
            break;
        }
        default: {
            break;
        }
    }

    lastDump(out);
}