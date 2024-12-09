void ts::CountryAvailabilityDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    if (size >= 1) {
        bool available = (data[0] & 0x80) != 0;
        data += 1; size -= 1;
        strm << margin << "Available: " << UString::YesNo(available) << std::endl;
        while (size >= 3) {
            strm << margin << "Country code: \"" << DeserializeLanguageCode(data) << "\"" << std::endl;
            data += 3; size -= 3;
        }
    }

    display.displayExtraData(data, size, indent);
}