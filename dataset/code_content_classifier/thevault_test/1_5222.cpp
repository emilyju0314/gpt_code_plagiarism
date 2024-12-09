void ts::LogicalChannelNumberDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    while (size >= 4) {
        const uint16_t service = GetUInt16(data);
        const uint8_t visible = (data[2] >> 7) & 0x01;
        const uint16_t channel = GetUInt16(data + 2) & 0x03FF;
        data += 4; size -= 4;
        strm << margin
             << UString::Format(u"Service Id: %5d (0x%04X), Visible: %1d, Channel number: %3d", {service, service, visible, channel})
             << std::endl;
    }

    display.displayExtraData(data, size, indent);
}