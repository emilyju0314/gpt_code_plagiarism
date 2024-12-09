void ts::SubtitlingDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    while (size >= 8) {
        uint8_t type = data[3];
        uint16_t comp_page = GetUInt16(data + 4);
        uint16_t ancil_page = GetUInt16(data + 6);
        strm << margin << UString::Format(u"Language: %s, Type: %d (0x%X)", {DeserializeLanguageCode(data), type, type}) << std::endl
             << margin << "Type: " << names::SubtitlingType(type) << std::endl
             << margin << UString::Format(u"Composition page: %d (0x%X), Ancillary page: %d (0x%X)", {comp_page, comp_page, ancil_page, ancil_page}) << std::endl;
        data += 8; size -= 8;
    }

    display.displayExtraData(data, size, indent);
}