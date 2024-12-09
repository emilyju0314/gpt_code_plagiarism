void ts::SVCExtensionDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    if (size >= 13) {
        strm << margin << UString::Format(u"Frame size: %dx%d", {GetUInt16(data), GetUInt16(data + 2)}) << std::endl
             << margin << UString::Format(u"Frame rate: %d frames / 256 seconds", {GetUInt16(data + 4)}) << std::endl
             << margin << UString::Format(u"Average bitrate: %d kb/s, maximum: %d kb/s", {GetUInt16(data + 6), GetUInt16(data + 8)}) << std::endl
             << margin << UString::Format(u"Dependency id: %d", {(data[10] >> 5) & 0x07}) << std::endl
             << margin << UString::Format(u"Quality id start: %d, end: %d", {(data[11] >> 4) & 0x0F, data[11] & 0x0F}) << std::endl
             << margin << UString::Format(u"Temporal id start: %d, end: %d", {(data[12] >> 5) & 0x07, (data[12] >> 2) & 0x07}) << std::endl
             << margin << UString::Format(u"No SEI NALunit present: %s", {(data[12] & 0x02) != 0}) << std::endl;
        data += 13; size -= 13;
    }

    display.displayExtraData(data, size, indent);
}