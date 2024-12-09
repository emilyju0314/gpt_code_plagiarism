void ts::AudioStreamDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    if (size >= 1) {
        strm << margin << UString::Format(u"Free format: %s, variable rate: %s", {UString::TrueFalse((data[0] & 0x80) != 0), UString::TrueFalse((data[0] & 0x08) != 0)}) << std::endl
             << margin << UString::Format(u"ID: %d, layer: %d", {(data[0] >> 6) & 0x01, (data[0] >> 4) & 0x03}) << std::endl;
        data++; size--;
    }

    display.displayExtraData(data, size, indent);
}