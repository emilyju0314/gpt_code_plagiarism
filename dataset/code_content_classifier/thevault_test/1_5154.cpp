void ts::TimeSliceFECIdentifierDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    if (size >= 3) {
        const bool time_slicing = (data[0] & 0x80) != 0;
        const uint8_t mpe_fec = (data[0] >> 5) & 0x03;
        const uint8_t frame_size = data[0] & 0x07;
        const uint8_t max_burst_duration = data[1];
        const uint8_t max_average_rate = (data[2] >> 4) & 0x0F;
        const uint8_t time_slice_fec_id = data[2] & 0x0F;
        data += 3; size -= 3;

        strm << margin << "Use time slice: " << UString::TrueFalse(time_slicing) << std::endl
             << margin << "MPE FEC: ";
        switch (mpe_fec) {
            case 0:  strm << "none"; break;
            case 1:  strm << "Reed-Solomon(255, 191, 64)"; break;
            default: strm << UString::Format(u"reserved value 0x%X", {mpe_fec}); break;
        }
        strm << std::endl << margin << "Frame size: ";
        switch (frame_size) {
            case 0:  strm << "512 kbits, 256 rows"; break;
            case 1:  strm << "1024 kbits, 512 rows"; break;
            case 2:  strm << "1536 kbits, 768 rows"; break;
            case 3:  strm << "2048 kbits, 1024 rows"; break;
            default: strm << UString::Format(u"reserved value 0x%X", {frame_size}); break;
        }
        strm << std::endl
             << margin << UString::Format(u"Max burst duration: 0x%X (%d)", {max_burst_duration, max_burst_duration}) << std::endl
             << margin << "Max average rate: ";
        switch (max_average_rate) {
            case 0:  strm << "16 kbps"; break;
            case 1:  strm << "32 kbps"; break;
            case 2:  strm << "64 kbps"; break;
            case 3:  strm << "128 kbps"; break;
            case 4:  strm << "256 kbps"; break;
            case 5:  strm << "512 kbps"; break;
            case 6:  strm << "1024 kbps"; break;
            case 7:  strm << "2048 kbps"; break;
            default: strm << UString::Format(u"reserved value 0x%X", {max_average_rate}); break;
        }
        strm << std::endl
             << margin << UString::Format(u"Time slice FEC id: 0x%X (%d)", {time_slice_fec_id, time_slice_fec_id}) << std::endl;
        if (size > 0) {
            strm << margin << "Id selector bytes:" << std::endl
                 << UString::Dump(data, size, UString::HEXA | UString::ASCII | UString::OFFSET, indent);
            data += size; size = 0;
        }
    }

    display.displayExtraData(data, size, indent);
}