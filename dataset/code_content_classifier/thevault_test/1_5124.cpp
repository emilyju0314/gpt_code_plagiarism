void ts::CellFrequencyLinkDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    while (size >= 7) {
        size_t len = data[6];
        strm << margin << UString::Format(u"- Cell id: 0x%X, frequency: %'d Hz", {GetUInt16(data), uint64_t(GetUInt32(data + 2)) * 10}) << std::endl;
        data += 7; size -= 7;

        while (size >= len && len >= 5) {
            strm << margin << UString::Format(u"  Subcell id ext: 0x%X, frequency: %'d Hz", {data[0], uint64_t(GetUInt32(data + 1)) * 10}) << std::endl;
            data += 5; size -= 5; len -= 5;
        }
        if (len > 0) {
            break;
        }
    }

    display.displayExtraData(data, size, indent);
}