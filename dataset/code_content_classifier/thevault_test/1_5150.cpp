void ts::CIAncillaryDataDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    // Important: With extension descriptors, the DisplayDescriptor() function is called
    // with extension payload. Meaning that data points after descriptor_tag_extension.
    // See ts::TablesDisplay::displayDescriptorData()

    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    if (size > 0) {
        strm << margin << "Ancillary data:" << std::endl
             << UString::Dump(data, size, UString::HEXA | UString::ASCII | UString::OFFSET, indent);
    }
}