void ts::AVCTimingAndHRDDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    if (size >= 1) {
        strm << margin << "HRD management valid: " << UString::TrueFalse((data[0] & 0x80) != 0) << std::endl;
        bool info_present = (data[0] & 0x01) != 0;
        data++; size--;

        bool ok = size >= 1;
        if (info_present) {
            const bool has_90kHz = (data[0] & 0x80) != 0;
            data++; size--;
            if (has_90kHz) {
                ok = size >= 8;
                if (ok) {
                    strm << margin << UString::Format(u"90 kHz: N = %'d, K = %'d", {GetUInt32(data), GetUInt32(data + 4)}) << std::endl;
                    data += 8; size -= 8;
                }
            }
            ok = ok && size >= 4;
            if (ok) {
                strm << margin << UString::Format(u"Num. units in tick: %'d", {GetUInt32(data)}) << std::endl;
                data += 4; size -= 4;
            }
        }
        if (ok && size >= 1) {
            strm << margin << "Fixed frame rate: " << UString::TrueFalse((data[0] & 0x80) != 0) << std::endl
                 << margin << "Temporal picture order count: " << UString::TrueFalse((data[0] & 0x40) != 0) << std::endl
                 << margin << "Picture to display conversion: " << UString::TrueFalse((data[0] & 0x20) != 0) << std::endl;
            data++; size--;
        }
    }

    display.displayExtraData(data, size, indent);
}