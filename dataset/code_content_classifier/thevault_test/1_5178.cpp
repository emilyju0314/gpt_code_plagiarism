void ts::ATSCTimeShiftedServiceDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    if (size >= 1) {
        size_t count = data[0] & 0x1F;
        data++; size--;
        strm << margin << "Number of services: " << count << std::endl;
        while (size >= 5 && count > 0) {
            const uint32_t n = GetUInt24(data + 2);
            strm << margin << UString::Format(u"- Time shift: %d mn, service: %d.%d", {GetUInt16(data) & 0x03FF, (n >> 10) & 0x03FF, n & 0x03FF}) << std::endl;
            data += 5; size -= 5; count--;
        }

    }

    display.displayExtraData(data, size, indent);
}