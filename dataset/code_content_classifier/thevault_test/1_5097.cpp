void ts::ExtendedEventDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    if (size >= 5) {
        const uint8_t desc_num = data[0];
        const UString lang(DeserializeLanguageCode(data + 1));
        size_t length = data[4];
        data += 5; size -= 5;
        if (length > size) {
            length = size;
        }
        strm << margin << "Descriptor number: " << int((desc_num >> 4) & 0x0F)
             << ", last: " << int(desc_num & 0x0F) << std::endl
             << margin << "Language: " << lang << std::endl;
        size -= length;
        while (length > 0) {
            const UString description(display.duck().fromDVBWithByteLength(data, length));
            const UString item(display.duck().fromDVBWithByteLength(data, length));
            strm << margin << "\"" << description << "\" : \"" << item << "\"" << std::endl;
        }
        const UString text(display.duck().fromDVBWithByteLength(data, size));
        strm << margin << "Text: \"" << text << "\"" << std::endl;
        data += length; size -= length;
    }

    display.displayExtraData(data, size, indent);
}