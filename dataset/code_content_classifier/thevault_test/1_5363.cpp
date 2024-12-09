void ts::AssociationTagDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    if (size >= 5) {
        const uint16_t tag = GetUInt16(data);
        const uint16_t use = GetUInt16(data + 2);
        const size_t len = std::min<size_t>(size - 5, GetUInt8(data + 4));
        data += 5; size -= 5;

        strm << margin << UString::Format(u"Association tag: 0x%X (%d), use: 0x%X (%d)", {tag, tag, use, use}) << std::endl;
        if (len > 0) {
            strm << margin << "Selector bytes:" << std::endl
                 << UString::Dump(data, len, UString::HEXA | UString::ASCII | UString::OFFSET, indent);
        }
        if (size > len) {
            strm << margin << "Private data:" << std::endl
                 << UString::Dump(data + len, size - len, UString::HEXA | UString::ASCII | UString::OFFSET, indent);
        }
        size = 0;
    }

    display.displayExtraData(data, size, indent);
}