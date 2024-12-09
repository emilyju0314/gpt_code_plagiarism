ts::UString foo::LogFooCASEMM(const ts::Section& section, size_t max_bytes)
{
    const uint8_t* data = section.payload();
    size_t size = section.payloadSize();

    // A FooCAS EMM starts with a 2-byte foo_id.
    return size < 2 ? ts::UString() : ts::UString::Format(u"Foo id: 0x%X, data: %s", {ts::GetUInt16(data), ts::UString::Dump(data + 2, std::min(max_bytes, size - 2), ts::UString::COMPACT)});
}