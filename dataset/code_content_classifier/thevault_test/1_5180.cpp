void ts::NorDigLogicalChannelDescriptorV2::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    while (size >= 2) {
        const uint8_t id = data[0];
        data++; size--;
        const UString name(display.duck().fromDVBWithByteLength(data, size));
        strm << margin << UString::Format(u"- Channel list id: 0x%X (%d), name: \"%s\"", {id, id, name});
        if (size < 3) {
            strm << std::endl;
            break;
        }
        strm << ", country code: \"" << DeserializeLanguageCode(data) << "\"" << std::endl;
        data += 3; size -= 3;
        if (size < 1) {
            break;
        }
        size_t len = data[0];
        data++; size--;
        while (len >= 4 && size >= 4) {
            const uint16_t service = GetUInt16(data);
            const uint8_t visible = (data[2] >> 7) & 0x01;
            const uint16_t channel = GetUInt16(data + 2) & 0x03FF;
            strm << margin
                 << UString::Format(u"  Service Id: %5d (0x%04X), Visible: %1d, Channel number: %3d", {service, service, visible, channel})
                 << std::endl;
            data += 4; size -= 4; len -= 4;
        }
        if (len != 0) {
            break;
        }
    }

    display.displayExtraData(data, size, indent);
}