void ts::ISPAccessModeDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    if (size >= 1) {
        strm << margin << UString::Format(u"Access mode: 0x%X (%s)", {data[0], AccessModeNames.name(data[0])}) << std::endl;
        data++; size--;
    }

    display.displayExtraData(data, size, indent);
}