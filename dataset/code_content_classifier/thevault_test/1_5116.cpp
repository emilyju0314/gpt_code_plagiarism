void ts::StreamEventDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());

    if (size >= 10) {
        const std::string margin(indent, ' ');

        // Extract common part
        const uint16_t id = GetUInt16(data);
        const uint64_t npt = GetUInt64(data + 2) & TS_UCONST64(0x00000001FFFFFFFF);
        data += 10; size -= 10;

        strm << margin << UString::Format(u"Event id: 0x%X (%d), NPT: 0x%09X (%d)", {id, id, npt, npt}) << std::endl;

        // Private part.
        if (size > 0) {
            strm << margin << "Private data:" << std::endl
                 << UString::Dump(data, size, UString::HEXA | UString::ASCII | UString::OFFSET, indent);
            data += size; size = 0;
        }
    }

    display.displayExtraData(data, size, indent);
}