void ts::EASInbandExceptionChannelsDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    if (size > 0) {
        uint8_t count = data[0];
        data++; size--;
        strm << margin << UString::Format(u"Exception channel count: %d", {count}) << std::endl;
        while (size >= 3 && count-- > 0) {
            strm << margin << UString::Format(u"  RF channel: %d, program number 0x%X (%d)", {data[0], GetUInt16(data + 1), GetUInt16(data + 1)}) << std::endl;
            data += 3; size -= 3;
        }
    }

    display.displayExtraData(data, size, indent);
}