void ts::CPDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    // Important: With extension descriptors, the DisplayDescriptor() function is called
    // with extension payload. Meaning that data points after descriptor_tag_extension.
    // See ts::TablesDisplay::displayDescriptorData()

    if (size >= 4) {
        std::ostream& strm(display.duck().out());
        const std::string margin(indent, ' ');

        uint16_t id = GetUInt16(data);
        uint16_t pid = GetUInt16(data + 2) & 0x1FFF;
        strm << margin << UString::Format(u"CP System Id: %s, CP PID: %d (0x%X)", {NameFromSection(u"CPSystemId", id, names::FIRST), pid, pid}) << std::endl;

        // CA private part.
        if (size > 4) {
            strm << margin << "Private CP data:" << std::endl
                 << UString::Dump(data + 4, size - 4, UString::HEXA | UString::ASCII | UString::OFFSET, indent);
        }
    }
    else {
        display.displayExtraData(data, size, indent);
    }
}