void ts::PDCDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    if (size >= 3) {
        const uint32_t date = GetUInt24(data);
        data += 3; size -= 3;
        strm << margin
             << UString::Format(u"Programme Identification Label: %02d-%02d %02d:%02d (MM-DD hh:mm)",
                                {(date >> 11) & 0x0F, (date >> 15) & 0x1F, (date >> 6) & 0x1F, date & 0x3F})
             << std::endl;
    }

    display.displayExtraData(data, size, indent);
}