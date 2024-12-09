void ts::FlexMuxTimingDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    if (size >= 8) {
        const uint16_t id = GetUInt16(data);
        const uint32_t res = GetUInt32(data + 2);
        const uint8_t len = GetUInt8(data + 6);
        const uint8_t fmx = GetUInt8(data + 7);
        data += 8; size -= 8;
        strm << margin << UString::Format(u"FCR ES ID: 0x%X (%d)", {id, id}) << std::endl
             << margin << UString::Format(u"FCR resolution: %'d cycles/second", {res}) << std::endl
             << margin << UString::Format(u"FCR length: %'d", {len}) << std::endl
             << margin << UString::Format(u"FMX rate length: %d", {fmx}) << std::endl;
    }

    display.displayExtraData(data, size, indent);
}