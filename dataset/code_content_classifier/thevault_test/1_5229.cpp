void ts::CaptionServiceDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    if (size >= 1) {
        size_t count = data[0] & 0x1F;
        data++; size--;
        strm << margin << "Number of services: " << count << std::endl;
        while (size >= 6 && count > 0) {
            const bool digital = (data[3] & 0x80) != 0;
            strm << margin << UString::Format(u"- Language: \"%s\", digital: %s", {DeserializeLanguageCode(data), digital});
            if (digital) {
                const uint8_t id = data[3] & 0x3F;
                strm << UString::Format(u", service: 0x%X (%d)", {id, id});
            }
            else {
                strm << UString::Format(u", line 21: %s", {(data[3] & 0x01) != 0});
            }
            strm << UString::Format(u", easy reader: %s, wide: %s", {(data[4] & 0x80) != 0, (data[4] & 0x40) != 0}) << std::endl;
            data += 6; size -= 6; count--;
        }
    }

    display.displayExtraData(data, size, indent);
}