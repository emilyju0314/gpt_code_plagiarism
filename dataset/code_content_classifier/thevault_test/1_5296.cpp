void ts::VideoDepthRangeDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    // Important: With extension descriptors, the DisplayDescriptor() function is called
    // with extension payload. Meaning that data points after descriptor_tag_extension.
    // See ts::TablesDisplay::displayDescriptorData()

    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');
    bool ok = true;

    while (ok && size >= 2) {
        const uint8_t type = data[0];
        size_t len = data[1];
        data += 2; size -= 2;
        strm << margin << UString::Format(u"- Range type: 0x%X (%d)", {type, type}) << std::endl;

        switch (type) {
            case 0:
                ok = len == 3;
                if (ok) {
                    const int32_t hint = GetInt24(data);
                    const int16_t max = SignExtend(int16_t(hint >> 12), 12);
                    const int16_t min = SignExtend(int16_t(hint), 12);
                    data += 3; size -= 3;
                    strm << margin << UString::Format(u"  Video max disparity hint: %d, min: %d", {max, min}) << std::endl;
                }
                break;
            case 1:
                ok = len == 0;
                break;
            default:
                ok = size >= len;
                if (ok && len > 0) {
                    strm << margin << "  Range selector bytes:" << std::endl
                         << UString::Dump(data, len, UString::HEXA | UString::ASCII | UString::OFFSET, indent + 2);
                    data += len; size -= len;
                }
                break;
        }
    }

    display.displayExtraData(data, size, indent);
}