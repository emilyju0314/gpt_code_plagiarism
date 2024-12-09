void ts::TargetRegionNameDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    // Important: With extension descriptors, the DisplayDescriptor() function is called
    // with extension payload. Meaning that data points after descriptor_tag_extension.
    // See ts::TablesDisplay::displayDescriptorData()

    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');
    bool ok = size >= 6;
    int index = 0;

    if (ok) {
        strm << margin << "Country code: \"" << DeserializeLanguageCode(data) << "\"" << std::endl
             << margin << "Language code: \"" << DeserializeLanguageCode(data + 3) << "\"" << std::endl;
        data += 6; size -= 6;
    }
    while (ok && size >= 1) {
        strm << margin << "- Region #" << index++ << std::endl;

        const int depth = (data[0] >> 6) & 0x03;
        const size_t len = data[0] & 0x3F;
        data++; size--;

        ok = size > len;
        if (ok) {
            strm << margin << "  Region name: \"" << display.duck().fromDVB(data, len) << "\"" << std::endl
                 << margin << UString::Format(u"  Primary region code: 0x%X (%d)", {data[len], data[len]}) << std::endl;
            data += len + 1; size -= len + 1;
        }
        if (ok && depth >= 2) {
            ok = size >= 1;
            if (ok) {
                strm << margin << UString::Format(u"  Secondary region code: 0x%X (%d)", {data[0], data[0]}) << std::endl;
                data++; size--;
            }
        }
        if (ok && depth >= 3) {
            ok = size >= 2;
            if (ok) {
                strm << margin << UString::Format(u"  Tertiary region code: 0x%X (%d)", {GetUInt16(data), GetUInt16(data)}) << std::endl;
                data += 2; size -= 2;
            }
        }
    }

    display.displayExtraData(data, size, indent);
}