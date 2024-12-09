void ts::SSUEventNameDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    if (size >= 4) {
        const UString lang(DeserializeLanguageCode(data));
        data += 3; size -= 3;
        const UString name(display.duck().fromDVBWithByteLength(data, size));
        const UString text(display.duck().fromDVBWithByteLength(data, size));
        strm << margin << "Language: " << lang << std::endl
             << margin << "Event name: \"" << name << "\"" << std::endl
             << margin << "Event text: \"" << text << "\"" << std::endl;
    }
    display.displayExtraData(data, size, indent);
}