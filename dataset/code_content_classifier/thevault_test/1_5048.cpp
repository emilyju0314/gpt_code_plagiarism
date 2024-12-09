void ts::MultiplexBufferUtilizationDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    if (size >= 4) {
        const bool valid = (data[0] & 0x80) != 0;
        const uint16_t low = GetUInt16(data) & 0x7FFF;
        const uint16_t upp = GetUInt16(data + 2) & 0x7FFF;
        strm << margin << "Bound valid: " << UString::YesNo(valid) << std::endl;
        if (valid) {
            strm << margin << UString::Format(u"LTW offset bounds: lower: 0x%X (%d), upper: 0x%X (%d)", {low, low, upp, upp}) << std::endl;
        }
        data += 4; size -= 4;
    }

    display.displayExtraData(data, size, indent);
}