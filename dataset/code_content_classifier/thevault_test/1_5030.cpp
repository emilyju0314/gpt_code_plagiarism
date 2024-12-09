void foo::FooTable::DisplaySection(ts::TablesDisplay& display, const ts::Section& section, int indent)
{
    std::ostream& strm(display.duck().out());
    const uint8_t* data = section.payload();
    size_t size = section.payloadSize();

    const uint16_t id = section.tableIdExtension();
    const ts::UString name(ts::UString::FromDVBWithByteLength(data, size, display.duck().dvbCharsetIn()));

    strm << ts::UString::Format(u"%*sFoo id: 0x%X (%d), name: \"%s\"", {indent, u"", id, id, name}) << std::endl;

    if (size >= 2) {
        size_t length = ts::GetUInt16(data) & 0x0FFF;
        data += 2; size -= 2;
        length = std::min(size, length);
        display.displayDescriptorList(section, data, length, indent);
        data += length; size -= length;
    }
    display.displayExtraData(data, size, indent);
}