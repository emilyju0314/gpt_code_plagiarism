void ts::TeletextDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    while (size >= 5) {
        const uint8_t type = data[3] >> 3;
        const uint8_t mag = data[3] & 0x07;
        const uint8_t page = data[4];
        Entry e;
        e.setFullNumber(mag, page);
        strm << margin << UString::Format(u"Language: %s, Type: %d (0x%X)", {DeserializeLanguageCode(data), type, type}) << std::endl
             << margin << "Type: " << names::TeletextType(type) << std::endl
             << margin << "Magazine: " << int(mag) << ", page: " << int(page) << ", full page: " << e.page_number << std::endl;
        data += 5; size -= 5;
    }

    display.displayExtraData(data, size, indent);
}