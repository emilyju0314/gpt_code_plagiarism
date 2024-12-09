void ts::PrivateDataIndicatorDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    if (size >= 4) {
        // Sometimes, the indicator is made of ASCII characters. Try to display them.
        strm << margin << UString::Format(u"Private data indicator: 0x%X", {GetUInt32(data)});
        display.duck().displayIfASCII(data, 4, u" (\"", u"\")");
        strm << std::endl;
        data += 4; size -= 4;
    }

    display.displayExtraData(data, size, indent);
}