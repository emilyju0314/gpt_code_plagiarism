void ts::SatelliteDeliverySystemDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    if (size >= 11) {
        const uint8_t east = data[6] >> 7;
        const uint8_t polar = (data[6] >> 5) & 0x03;
        const uint8_t roll_off = (data[6] >> 3) & 0x03;
        const uint8_t mod_system = (data[6] >> 2) & 0x01;
        const uint8_t mod_type = data[6] & 0x03;
        const uint8_t fec_inner = data[10] & 0x0F;
        std::string freq, srate, orbital;
        BCDToString(freq, data, 8, 3);
        BCDToString(orbital, data + 4, 4, 3);
        BCDToString(srate, data + 7, 7, 3, true);
        data += 11; size -= 11;

        strm << margin << "Orbital position: " << orbital
             << " degree, " << (east ? "east" : "west") << std::endl
             << margin << "Frequency: " << freq << " GHz" << std::endl
             << margin << "Symbol rate: " << srate << " Msymbol/s" << std::endl
             << margin << "Polarization: ";
        switch (polar) {
            case 0:  strm << "linear - horizontal"; break;
            case 1:  strm << "linear - vertical"; break;
            case 2:  strm << "circular - left"; break;
            case 3:  strm << "circular - right"; break;
            default: assert(false);
        }
        strm << std::endl << margin << "Modulation: " << (mod_system == 0 ? "DVB-S" : "DVB-S2") << ", ";
        switch (mod_type) {
            case 0:  strm << "Auto"; break;
            case 1:  strm << "QPSK"; break;
            case 2:  strm << "8PSK"; break;
            case 3:  strm << "16-QAM"; break;
            default: assert(false);
        }
        if (mod_system == 1) {
            switch (roll_off) {
                case 0:  strm << ", alpha=0.35"; break;
                case 1:  strm << ", alpha=0.25"; break;
                case 2:  strm << ", alpha=0.20"; break;
                case 3:  strm << ", undefined roll-off (3)"; break;
                default: assert(false);
            }
        }
        strm << std::endl << margin << "Inner FEC: ";
        switch (fec_inner) {
            case 0:  strm << "not defined"; break;
            case 1:  strm << "1/2"; break;
            case 2:  strm << "2/3"; break;
            case 3:  strm << "3/4"; break;
            case 4:  strm << "5/6"; break;
            case 5:  strm << "7/8"; break;
            case 6:  strm << "8/9"; break;
            case 7:  strm << "3/5"; break;
            case 8:  strm << "4/5"; break;
            case 9:  strm << "9/10"; break;
            case 15: strm << "none"; break;
            default: strm << "code " << int(fec_inner) << " (reserved)"; break;
        }
        strm << std::endl;
    }

    display.displayExtraData(data, size, indent);
}