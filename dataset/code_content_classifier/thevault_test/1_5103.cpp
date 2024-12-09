void foo::DisplayFooCASECM(ts::TablesDisplay& display, const ts::Section& section, int indent)
{
    std::ostream& strm(display.duck().out());
    const uint8_t* data = section.payload();
    size_t size = section.payloadSize();

    if (size >= 2) {
        // A FooCAS ECM starts with a 2-byte foo_id.
        strm << ts::UString::Format(u"%*sFoo id: 0x%X", {indent, u"", ts::GetUInt16(data)}) << std::endl
             << ts::UString::Format(u"%*sData: %s", {indent, u"", ts::UString::Dump(data + 2, size - 2, ts::UString::COMPACT)}) << std::endl;
    }
}