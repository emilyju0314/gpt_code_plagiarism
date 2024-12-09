void ts::ApplicationIconsDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    if (size > 0) {
        strm << margin << "Icon locator: \"" << display.duck().fromDVBWithByteLength(data, size) << "\"" << std::endl;
        if (size >= 2) {
            const uint16_t flags = GetUInt16(data);
            strm << margin << UString::Format(u"Icon flags: 0x%X", {flags}) << std::endl;
            for (uint16_t mask = 0x0001; mask != 0; mask <<= 1) {
                if ((flags & mask) != 0) {
                    strm << margin << "  - " << NameFromSection(u"ApplicationIconFlags", mask) << std::endl;
                }
            }
            if (size > 2) {
                strm << margin << "Reserved bytes:" << std::endl
                     << UString::Dump(data + 2, size - 2, UString::HEXA | UString::ASCII | UString::OFFSET, indent + 2);
            }
        }
    }
}