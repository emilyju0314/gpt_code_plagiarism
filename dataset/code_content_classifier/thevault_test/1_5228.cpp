void ts::VCT::DisplaySection(TablesDisplay& display, const ts::Section& section, int indent)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');
    const uint8_t* data = section.payload();
    size_t size = section.payloadSize();

    if (size >= 2) {
        // Fixed part.
        uint16_t num_channels = data[1];
        strm << margin << UString::Format(u"Transport stream id: 0x%X (%d)", {section.tableIdExtension(), section.tableIdExtension()}) << std::endl
             << margin << UString::Format(u"Protocol version: %d, number of channels: %d", {data[0], num_channels}) << std::endl;
        data += 2; size -= 2;

        // Loop on all channel definitions.
        while (num_channels > 0 && size >= 32) {
            // The short name is at most 7 UTF-16 characters.
            UString name;
            for (size_t i = 0; i < 7; i++) {
                const uint16_t c = GetUInt16(data + 2*i);
                if (c == 0) {
                    break; // padding zeroes
                }
                else {
                    name.push_back(UChar(c));
                }
            }
            const uint32_t num = GetUInt24(data + 14);
            const uint8_t flags = data[26];
            strm << margin << UString::Format(u"- Channel %d.%d, short name: \"%s\"", {(num >> 10) & 0x03FF, num & 0x03FF, name}) << std::endl
                 << margin << UString::Format(u"  Modulation: %s, frequency: %'d", {NameFromSection(u"ATSCModulationModes", data[17]), GetUInt32(data + 18)}) << std::endl
                 << margin << UString::Format(u"  TS id: 0x%X (%d), program number: 0x%X (%d)", {GetUInt16(data + 22), GetUInt16(data + 22), GetUInt16(data + 24), GetUInt16(data + 24)}) << std::endl
                 << margin << UString::Format(u"  ETM location: %d, access controlled: %s", {(flags >> 6) & 0x03, UString::YesNo((flags & 0x20) != 0)}) << std::endl;
            if (section.tableId() == TID_CVCT) {
                // The following two bits are used in CVCT only.
                strm << margin << UString::Format(u"  Path select: %d, out of band: %s", {(flags >> 3) & 0x01, UString::YesNo((flags & 0x04) != 0)}) << std::endl;
            }
            strm << margin << UString::Format(u"  Hidden: %s, hide guide: %s", {UString::YesNo((flags & 0x10) != 0), UString::YesNo((flags & 0x02) != 0)}) << std::endl
                 << margin << UString::Format(u"  Service type: %s, source id: 0x%X (%d)", {NameFromSection(u"ATSCServiceType", data[27] & 0x3F), GetUInt16(data + 28), GetUInt16(data + 28)}) << std::endl;

            // Descriptors for this channel. Use fake PDS for ATSC.
            size_t info_length = GetUInt16(data + 30) & 0x03FF; // 10 bits only
            data += 32; size -= 32;
            info_length = std::min(info_length, size);
            display.displayDescriptorList(section, data, info_length, indent + 2);
            data += info_length; size -= info_length;
            num_channels--;
        }
        if (num_channels == 0 && size >= 2) {
            // Common descriptors. Use fake PDS for ATSC.
            size_t info_length = GetUInt16(data) & 0x03FF; // 10 bits only
            data += 2; size -= 2;
            info_length = std::min(info_length, size);
            if (info_length > 0) {
                strm << margin << "- Global descriptors:" << std::endl;
                display.displayDescriptorList(section, data, info_length, indent + 2);
                data += info_length; size -= info_length;
            }
        }
    }

    display.displayExtraData(data, size, indent);
}