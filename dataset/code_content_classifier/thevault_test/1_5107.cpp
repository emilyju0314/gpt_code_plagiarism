void foo::DisplayFooCASCADescriptor(ts::TablesDisplay& display, const uint8_t* data, size_t size, int indent, ts::TID tid)
{
    std::ostream& strm(display.duck().out());

    if (size >= 2) {
        // The private part of a FooCAS CA-descriptor starts with a 2-byte foo_id.
        strm << ts::UString::Format(u"%*sFoo id: 0x%X", {indent, u"", ts::GetUInt16(data)}) << std::endl
             << ts::UString::Format(u"%*sData: %s", {indent, u"", ts::UString::Dump(data + 2, size - 2, ts::UString::COMPACT)}) << std::endl;
    }
}