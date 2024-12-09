void ts::SpliceAvailDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    if (size >= 8) {
        strm << margin << UString::Format(u"Identifier: 0x%X", {GetUInt32(data)});
        display.duck().displayIfASCII(data, 4, u" (\"", u"\")");
        strm << std::endl << margin << UString::Format(u"Provider id: 0x%X", {GetUInt32(data + 4)}) << std::endl;
        data += 8; size -= 8;
    }

    display.displayExtraData(data, size, indent);
}