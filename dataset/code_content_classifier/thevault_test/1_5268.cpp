void ts::MultiplexBufferDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    if (size >= 6) {
        const uint32_t mb = GetUInt24(data);
        const uint32_t tb = GetUInt24(data + 3);
        data += 6; size -= 6;
        strm << margin << UString::Format(u"MB buffer size: %'d bytes", {mb}) << std::endl
             << margin << UString::Format(u"TB leak rate: %'d (%'d bits/s)", {tb, 400 * tb}) << std::endl;
    }

    display.displayExtraData(data, size, indent);
}