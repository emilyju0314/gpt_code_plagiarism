void ts::TerrestrialDeliverySystemDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    if (size >= 11) {
        uint32_t cfreq = GetUInt32(data);
        uint8_t bwidth = data[4] >> 5;
        uint8_t prio = (data[4] >> 4) & 0x01;
        uint8_t tslice = (data[4] >> 3) & 0x01;
        uint8_t mpe_fec = (data[4] >> 2) & 0x01;
        uint8_t constel = data[5] >> 6;
        uint8_t hierarchy = (data[5] >> 3) & 0x07;
        uint8_t rate_hp = data[5] & 0x07;
        uint8_t rate_lp = data[6] >> 5;
        uint8_t guard = (data[6] >> 3) & 0x03;
        uint8_t transm = (data[6] >> 1) & 0x03;
        bool other_freq = (data[6] & 0x01) != 0;
        data += 11; size -= 11;

        strm << margin << "Centre frequency: " << UString::Decimal(10 * uint64_t(cfreq)) << " Hz, Bandwidth: ";
        switch (bwidth) {
            case 0:  strm << "8 MHz"; break;
            case 1:  strm << "7 MHz"; break;
            case 2:  strm << "6 MHz"; break;
            case 3:  strm << "5 MHz"; break;
            default: strm << "code " << int(bwidth) << " (reserved)"; break;
        }
        strm << std::endl
             << margin << "Priority: " << (prio ? "high" : "low")
             << ", Time slicing: " << (tslice ? "unused" : "used")
             << ", MPE-FEC: " << (mpe_fec ? "unused" : "used")
             << std::endl
             << margin << "Constellation pattern: ";
        switch (constel) {
            case 0:  strm << "QPSK"; break;
            case 1:  strm << "16-QAM"; break;
            case 2:  strm << "64-QAM"; break;
            case 3:  strm << "reserved"; break;
            default: assert(false);
        }
        strm << std::endl << margin << "Hierarchy: ";
        assert(hierarchy < 8);
        switch (hierarchy & 0x03) {
            case 0:  strm << "non-hierarchical"; break;
            case 1:  strm << "alpha = 1"; break;
            case 2:  strm << "alpha = 2"; break;
            case 3:  strm << "alpha = 4"; break;
            default: assert(false);
        }
        strm << ", " << ((hierarchy & 0x04) ? "in-depth" : "native")
             << " interleaver" << std::endl
             << margin << "Code rate: high prio: ";
        switch (rate_hp) {
            case 0:  strm << "1/2"; break;
            case 1:  strm << "2/3"; break;
            case 2:  strm << "3/4"; break;
            case 3:  strm << "5/6"; break;
            case 4:  strm << "7/8"; break;
            default: strm << "code " << int(rate_hp) << " (reserved)"; break;
        }
        strm << ", low prio: ";
        switch (rate_lp) {
            case 0:  strm << "1/2"; break;
            case 1:  strm << "2/3"; break;
            case 2:  strm << "3/4"; break;
            case 3:  strm << "5/6"; break;
            case 4:  strm << "7/8"; break;
            default: strm << "code " << int(rate_lp) << " (reserved)"; break;
        }
        strm << std::endl << margin << "Guard interval: ";
        switch (guard) {
            case 0:  strm << "1/32"; break;
            case 1:  strm << "1/16"; break;
            case 2:  strm << "1/8"; break;
            case 3:  strm << "1/4"; break;
            default: assert(false);
        }
        strm << std::endl << margin << "OFDM transmission mode: ";
        switch (transm) {
            case 0:  strm << "2k"; break;
            case 1:  strm << "8k"; break;
            case 2:  strm << "4k"; break;
            case 3:  strm << "reserved"; break;
            default: assert(false);
        }
        strm << ", other frequencies: " << UString::YesNo(other_freq) << std::endl;
    }

    display.displayExtraData(data, size, indent);
}