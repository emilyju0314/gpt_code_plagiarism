void ts::IPMACPlatformNameDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    if (size >= 3) {
        strm << margin << "Language: " << DeserializeLanguageCode(data) << std::endl
             << margin << "Platform name: " << display.duck().fromDVB(data + 3, size - 3) << std::endl;
        size = 0;
    }

    display.displayExtraData(data, size, indent);
}