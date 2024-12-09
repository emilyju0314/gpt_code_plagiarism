void ts::PESPlugin::handleSEI(PESDemux& demux, const PESPacket& pkt, uint32_t sei_type, size_t offset, size_t size)
{
    if (!_dump_avc_sei || (!_sei_type_filter.empty() && _sei_type_filter.find(sei_type) == _sei_type_filter.end())) {
        return;
    }

    // Check if we must filter UUID on SEI's.
    if (!_sei_uuid_filter.empty()) {
        // Filter out SEI's other than user_data_unregistered (or SEI too short).
        if (sei_type != AVC_SEI_USER_DATA_UNREG || size < AVC_SEI_UUID_SIZE) {
            return;
        }
        // Check if the UUID (in the 16 first bytes of the SEI payload) must be filtered.
        bool found = false;
        for (std::list<ByteBlock>::const_iterator it = _sei_uuid_filter.begin(); !found && it != _sei_uuid_filter.end(); ++it) {
            assert(it->size() == AVC_SEI_UUID_SIZE);
            found = ::memcmp(it->data(), pkt.payload() + offset, AVC_SEI_UUID_SIZE) == 0;
        }
        if (!found) {
            // We don't want to dump this one.
            return;
        }
    }

    // Now display the SEI.
    std::ostream& out(_outfile.is_open() ? _outfile : std::cout);
    out << UString::Format(u"* PID 0x%X, SEI type %s", {pkt.getSourcePID(), NameFromSection(u"AVCSEIType", sei_type, names::FIRST)})
        << std::endl
        << UString::Format(u"  Offset in PES payload: %d, size: %d bytes", {offset, size})
        << std::endl;

    size_t dsize = size;
    out << "  AVC SEI";
    if (_max_dump_size > 0 && dsize > _max_dump_size) {
        dsize = _max_dump_size;
        out << " (truncated)";
    }
    out << ":" << std::endl << UString::Dump(pkt.payload() + offset, dsize, _hexa_flags | UString::ASCII, 4, _hexa_bpl);
}