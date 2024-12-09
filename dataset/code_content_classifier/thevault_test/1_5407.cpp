void ts::ProtectionMessageDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    // Important: With extension descriptors, the DisplayDescriptor() function is called
    // with extension payload. Meaning that data points after descriptor_tag_extension.
    // See ts::TablesDisplay::displayDescriptorData()

    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    if (size >= 1) {
        size_t count = data[0] & 0x0F;
        data++; size--;
        strm << margin << UString::Format(u"Component count: %d", {count}) << std::endl;
        while (count > 0 && size > 0) {
            strm << margin << UString::Format(u"Component tag: 0x%0X (%d)", {data[0], data[0]}) << std::endl;
            data++; size--; count--;
        }
    }

    display.displayExtraData(data, size, indent);
}