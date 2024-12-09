void ts::MessageDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    // Important: With extension descriptors, the DisplayDescriptor() function is called
    // with extension payload. Meaning that data points after descriptor_tag_extension.
    // See ts::TablesDisplay::displayDescriptorData()

    if (size >= 4) {
        std::ostream& strm(display.duck().out());
        const std::string margin(indent, ' ');
        strm << margin << "Message id: " << int(data[0])
             << ", language: " << DeserializeLanguageCode(data + 1) << std::endl
             << margin << "Message: \"" << display.duck().fromDVB(data + 4, size - 4) << "\"" << std::endl;
    }
    else {
        display.displayExtraData(data, size, indent);
    }
}