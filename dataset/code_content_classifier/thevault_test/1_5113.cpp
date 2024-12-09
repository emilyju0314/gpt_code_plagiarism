void ts::PMT::DisplaySection(TablesDisplay& display, const ts::Section& section, int indent)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');
    const uint8_t* data = section.payload();
    size_t size = section.payloadSize();

    if (size >= 4) {
        // Fixed part
        PID pid = GetUInt16(data) & 0x1FFF;
        size_t info_length = GetUInt16(data + 2) & 0x0FFF;
        data += 4; size -= 4;
        if (info_length > size) {
            info_length = size;
        }
        strm << margin << UString::Format(u"Program: %d (0x%X)", {section.tableIdExtension(), section.tableIdExtension()})
             << ", PCR PID: ";
        if (pid == PID_NULL) {
            strm << "none";
        }
        else {
            strm << pid << UString::Format(u" (0x%X)", {pid});
        }
        strm << std::endl;

        // Process and display "program info"
        if (info_length > 0) {
            strm << margin << "Program information:" << std::endl;
            display.displayDescriptorList(section, data, info_length, indent);
        }
        data += info_length; size -= info_length;

        // Process and display "elementary stream info"
        while (size >= 5) {
            uint8_t stream = *data;
            PID es_pid = GetUInt16(data + 1) & 0x1FFF;
            size_t es_info_length = GetUInt16(data + 3) & 0x0FFF;
            data += 5; size -= 5;
            if (es_info_length > size) {
                es_info_length = size;
            }
            strm << margin << "Elementary stream: type " << names::StreamType(stream, names::FIRST)
                 << ", PID: " << es_pid << UString::Format(u" (0x%X)", {es_pid}) << std::endl;
            display.displayDescriptorList(section, data, es_info_length, indent);
            data += es_info_length; size -= es_info_length;
        }
    }

    display.displayExtraData(data, size, indent);
}