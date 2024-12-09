void ts::SDT::DisplaySection(TablesDisplay& display, const ts::Section& section, int indent)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');
    const uint8_t* data = section.payload();
    size_t size = section.payloadSize();

    strm << margin << UString::Format(u"Transport Stream Id: %d (0x%X)", {section.tableIdExtension(), section.tableIdExtension()}) << std::endl;

    if (size >= 2) {
        uint16_t nwid = GetUInt16(data);
        strm << margin << UString::Format(u"Original Network Id: %d (0x%04X)", {nwid, nwid}) << std::endl;
        data += 2; size -= 2;
        if (size >= 1) {
            data += 1; size -= 1; // unused byte
        }

        // Loop across all services
        while (size >= 5) {
            uint16_t servid = GetUInt16(data);
            bool eits = (data[2] >> 1) & 0x01;
            bool eitpf = data[2] & 0x01;
            uint16_t length_bytes = GetUInt16(data + 3);
            uint8_t running_status = uint8_t(length_bytes >> 13);
            bool ca_mode = (length_bytes >> 12) & 0x01;
            size_t length = length_bytes & 0x0FFF;
            data += 5; size -= 5;
            if (length > size) {
                length = size;
            }
            strm << margin << UString::Format(u"Service Id: %d (0x%04X)", {servid, servid})
                 << ", EITs: " << UString::YesNo(eits)
                 << ", EITp/f: " << UString::YesNo(eitpf)
                 << ", CA mode: " << (ca_mode ? "controlled" : "free")
                 << std::endl << margin
                 << "Running status: " << names::RunningStatus(running_status)
                 << std::endl;
            display.displayDescriptorList(section, data, length, indent);
            data += length; size -= length;
        }
    }

    display.displayExtraData(data, size, indent);
}