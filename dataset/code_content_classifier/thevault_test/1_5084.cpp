void ts::MultilingualServiceNameDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    while (size >= 4) {
        const size_t prov_len = std::min<size_t>(data[3], size - 4);
        strm << margin
             << "Language: " << DeserializeLanguageCode(data)
             << ", provider: \"" << display.duck().fromDVB(data + 4, prov_len) << "\"";
        data += 4 + prov_len; size -= 4 + prov_len;
        if (size >= 1) {
            const size_t name_len = std::min<size_t>(data[0], size - 1);
            strm << ", service: \"" << display.duck().fromDVB(data + 1, name_len) << "\"";
            data += 1 + name_len; size -= 1 + name_len;
        }
        strm << std::endl;
    }

    display.displayExtraData(data, size, indent);
}