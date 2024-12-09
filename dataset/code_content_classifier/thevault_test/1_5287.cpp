void ts::ContentDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    while (size >= 2) {
        uint8_t content = data[0];
        uint8_t user = data[1];
        data += 2; size -= 2;
        strm << margin << UString::Format(u"Content: %s / User: 0x%X", {names::Content(content, names::FIRST), user}) << std::endl;
    }

    display.displayExtraData(data, size, indent);
}