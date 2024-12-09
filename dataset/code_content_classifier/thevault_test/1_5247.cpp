void ts::UNT::DisplaySection(TablesDisplay& display, const ts::Section& section, int indent)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');
    const uint8_t* data = section.payload();
    size_t size = section.payloadSize();

    if (size >= 4) {

        // Fixed part
        const uint8_t action_type = section.tableIdExtension() >> 8;
        const uint8_t oui_hash = section.tableIdExtension() & 0xFF;
        const uint8_t comp_hash = data[0] ^ data[1] ^ data[2];
        const uint32_t oui = GetUInt24(data);
        const uint8_t processing_order = data[3];
        data += 4; size -= 4;

        strm << margin << "OUI: " << names::OUI(oui, names::HEXA_FIRST) << std::endl
             << margin
             << UString::Format(u"Action type: 0x%X, processing order: 0x%X, OUI hash: 0x%X (%s)",
                                {action_type, processing_order, oui_hash,
                                 oui_hash == comp_hash ? u"valid" : UString::Format(u"invalid, should be 0x%X", {comp_hash})})
             << std::endl
             << margin << "Common descriptors:" << std::endl;

        // Display common descriptor loop.
        if (DisplayDescriptorList(display, section, data, size, indent + 2)) {
            // Loop on sets of devices.
            strm << margin << "Sets of devices:" << std::endl;
            if (size == 0) {
                strm << margin << "  None" << std::endl;
            }
            else {
                size_t dev_index = 0;
                while (size > 0) {
                    strm << margin << "  - Devices " << dev_index++ << ":" << std::endl;
                    if (!DisplayDevices(display, section, data, size, indent + 4)) {
                        break;
                    }
                }
            }
        }
    }

    display.displayExtraData(data, size, indent);
}