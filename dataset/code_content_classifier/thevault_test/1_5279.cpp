void ts::SelectionInformationTable::DisplaySection(TablesDisplay& display, const ts::Section& section, int indent)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');
    const uint8_t* data = section.payload();
    size_t size = section.payloadSize();

    if (size >= 2) {
        // Fixed part
        size_t info_length = GetUInt16(data) & 0x0FFF;
        data += 2; size -= 2;
        if (info_length > size) {
            info_length = size;
        }

        // Process and display global descriptor list.
        if (info_length > 0) {
            strm << margin << "Global information:" << std::endl;
            display.displayDescriptorList(section, data, info_length, indent);
        }
        data += info_length; size -= info_length;

        // Process and display "service info"
        while (size >= 4) {
            const uint16_t id = GetUInt16(data);
            const uint8_t rs = (data[2] >> 4) & 0x07;
            info_length = GetUInt16(data + 2) & 0x0FFF;
            data += 4; size -= 4;
            if (info_length > size) {
                info_length = size;
            }
            strm << margin << UString::Format(u"Service id: %d (0x%X), Status: %s", {id, id, RST::RunningStatusNames.name(rs)}) << std::endl;
            display.displayDescriptorList(section, data, info_length, indent);
            data += info_length; size -= info_length;
        }
    }

    display.displayExtraData(data, size, indent);
}