void ts::FMCDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    while (size >= 3) {
        const uint16_t id = GetUInt16(data);
        const uint8_t fmc = data[2];
        data += 3; size -= 3;
        strm << margin << UString::Format(u"ES id: 0x%X (%d), FlexMux channel: 0x%X (%d)", {id, id, fmc, fmc}) << std::endl;
    }

    display.displayExtraData(data, size, indent);
}