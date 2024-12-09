bool ts::UNT::DisplayDevices(TablesDisplay& display, const Section& section, const uint8_t*& data, size_t& remain, int indent)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    // Display compatibility descriptor.
    if (!DisplayCompatibilityDescriptorList(display, section, data, remain, indent) || remain < 2) {
        return false;
    }

    // Get platform loop length.
    const uint8_t* const data_end = data + 2 + GetUInt16(data);
    data += 2;
    remain -= 2;

    // Display platform descriptions.
    size_t platform_index = 0;
    while (data < data_end) {
        strm << margin << "Platform " << platform_index++ << ":" << std::endl
             << margin << "  Target descriptors:" << std::endl;
        if (!DisplayDescriptorList(display, section, data, remain, indent + 2)) {
            return false;
        }
        strm << margin << "  Operational descriptors:" << std::endl;
        if (!DisplayDescriptorList(display, section, data, remain, indent + 2)) {
            return false;
        }
    }
    return true;
}