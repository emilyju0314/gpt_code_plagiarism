void ts::DVBAC4Descriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    // Important: With extension descriptors, the DisplayDescriptor() function is called
    // with extension payload. Meaning that data points after descriptor_tag_extension.
    // See ts::TablesDisplay::displayDescriptorData()

    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    if (size >= 1) {
        const uint8_t flags = data[0];
        data++; size--;
        if ((flags & 0x80) != 0 && size >= 1) {
            uint8_t type = data[0];
            data++; size--;
            strm << margin
                 << UString::Format(u"Dialog enhancement enabled: %d, channel mode: %s",
                                    {(type >> 7) & 0x01, NameFromSection(u"AC4ChannelMode", (type >> 5) & 0x03, names::FIRST)})
                 << std::endl;
        }
        if ((flags & 0x40) != 0 && size >= 1) {
            const size_t toc_size = std::min<size_t>(data[0], size - 1);
            if (toc_size > 0) {
                strm << margin << "AC-4 TOC (in DSI):" << std::endl
                     << UString::Dump(data + 1, toc_size, UString::HEXA | UString::ASCII | UString::OFFSET, indent + 2);

            }
            data += 1 + toc_size; size -= 1 + toc_size;
        }
        if (size > 0) {
            strm << margin << "Additional information:" << std::endl
                 << UString::Dump(data, size, UString::HEXA | UString::ASCII | UString::OFFSET, indent + 2);
            data += size; size = 0;
        }
    }

    display.displayExtraData(data, size, indent);
}