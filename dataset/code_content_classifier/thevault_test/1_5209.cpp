void ts::AbstractMultilingualDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    while (size >= 4) {
        const size_t len = std::min<size_t>(data[3], size - 4);
        strm << margin
             << "Language: " << DeserializeLanguageCode(data)
             << ", name: \"" << display.duck().fromDVB(data + 4, len) << "\""
             << std::endl;
        data += 4 + len; size -= 4 + len;
    }

    display.displayExtraData(data, size, indent);
}