void ts::ETT::DisplaySection(TablesDisplay& display, const ts::Section& section, int indent)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');
    const uint8_t* data = section.payload();
    size_t size = section.payloadSize();

    if (size >= 5) {
        // Fixed part.
        uint32_t id = GetUInt32(data + 1);
        strm << margin << UString::Format(u"ETT table id extension: 0x%X (%d)", {section.tableIdExtension(), section.tableIdExtension()}) << std::endl
             << margin << UString::Format(u"Protocol version: %d, ETM id: 0x%X (%d)", {data[0], id, id}) << std::endl;
        data += 5; size -= 5;
        ATSCMultipleString::Display(display, u"Extended text message: ", indent, data, size);
    }

    display.displayExtraData(data, size, indent);
}