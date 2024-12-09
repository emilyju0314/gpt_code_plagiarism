void ts::DTSDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    if (size >= 5) {
        uint8_t sample_rate_code = (data[0] >> 4) & 0x0F;
        uint8_t bit_rate_code = (GetUInt16(data) >> 6) & 0x3F;
        uint8_t nblks = (GetUInt16(data + 1) >> 7) & 0x7F;
        uint16_t fsize = (GetUInt16(data + 2) >> 1) & 0x3FFF;
        uint8_t surround_mode = (GetUInt16(data + 3) >> 3) & 0x3F;
        bool lfe_flag = ((data[4] >> 2) & 0x01) != 0;
        uint8_t extended_surround_flag = data[4] & 0x03;
        data += 5; size -= 5;

        strm << margin << "Sample rate code: " << names::DTSSampleRateCode(sample_rate_code) << std::endl
             << margin << "Bit rate code: " << names::DTSBitRateCode(bit_rate_code) << std::endl
             << margin << "NBLKS: " << int(nblks) << std::endl
             << margin << "FSIZE: " << int(fsize) << std::endl
             << margin << "Surround mode: " << names::DTSSurroundMode(surround_mode) << std::endl
             << margin << "LFE (Low Frequency Effect) audio channel: " << UString::OnOff(lfe_flag) << std::endl
             << margin << "Extended surround flag: " << names::DTSExtendedSurroundMode(extended_surround_flag) << std::endl;

        if (size > 0) {
            strm << margin << "Additional information:" << std::endl
                 << UString::Dump(data, size, UString::HEXA | UString::ASCII | UString::OFFSET, indent);
            data += size; size = 0;
        }
    }

    display.displayExtraData(data, size, indent);
}