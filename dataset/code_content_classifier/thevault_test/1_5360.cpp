void ts::ApplicationDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    if (size >= 1) {
        size_t len = std::min<size_t>(data[0], size - 1);
        data++; size--;
        while (size >= 5 && len >= 5) {
            const uint16_t pr = GetUInt16(data);
            strm << margin << UString::Format(u"Profile: 0x%X (%d), version: %d.%d.%d", {pr, pr, data[2], data[3], data[4]}) << std::endl;
            data += 5; size -= 5; len -= 5;
        }
        if (size >= 1) {
            strm << margin
                 << UString::Format(u"Service bound: %d, visibility: %d, priority: %d", {data[0] >> 7, (data[0] >> 5) & 0x03, data[1]})
                 << std::endl;
            data += 2; size -= 2;
        }
        while (size > 0) {
            strm << margin << UString::Format(u"Transport protocol label: 0x%X (%d)", {data[0], data[0]}) << std::endl;
            data++; size--;
        }
    }

    display.displayExtraData(data, size, indent);
}