void ts::StreamModeDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    if (size >= 2) {
        const uint8_t mode = GetUInt8(data);
        data += 2; size -= 2;
        strm << margin << UString::Format(u"Stream mode: %s", {NameFromSection(u"DSMCCStreamMode", mode, names::HEXA_FIRST)}) << std::endl;
    }

    display.displayExtraData(data, size, indent);
}