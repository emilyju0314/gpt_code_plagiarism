void ts::CableDeliverySystemDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    if (size >= 11) {
        uint8_t fec_outer = data[5] & 0x0F;
        uint8_t modulation = data[6];
        uint8_t fec_inner = data[10] & 0x0F;
        std::string freq, srate;
        BCDToString(freq, data, 8, 4);
        BCDToString(srate, data + 7, 7, 3, true);
        data += 11; size -= 11;

        strm << margin << "Frequency: " << freq << " MHz" << std::endl
             << margin << "Symbol rate: " << srate << " Msymbol/s" << std::endl
             << margin << "Modulation: ";
        switch (modulation) {
            case 0:  strm << "not defined"; break;
            case 1:  strm << "16-QAM"; break;
            case 2:  strm << "32-QAM"; break;
            case 3:  strm << "64-QAM"; break;
            case 4:  strm << "128-QAM"; break;
            case 5:  strm << "256-QAM"; break;
            default: strm << "code " << int(modulation) << " (reserved)"; break;
        }
        strm << std::endl << margin << "Outer FEC: ";
        switch (fec_outer) {
            case 0:  strm << "not defined"; break;
            case 1:  strm << "none"; break;
            case 2:  strm << "RS(204/188)"; break;
            default: strm << "code " << int(fec_outer) << " (reserved)"; break;
        }
        strm << ", Inner FEC: ";
        switch (fec_inner) {
            case 0:  strm << "not defined"; break;
            case 1:  strm << "1/2 conv. code rate"; break;
            case 2:  strm << "2/3 conv. code rate"; break;
            case 3:  strm << "3/4 conv. code rate"; break;
            case 4:  strm << "5/6 conv. code rate"; break;
            case 5:  strm << "7/8 conv. code rate"; break;
            case 6:  strm << "8/9 conv. code rate"; break;
            case 7:  strm << "3/5 conv. code rate"; break;
            case 8:  strm << "4/5 conv. code rate"; break;
            case 9:  strm << "9/10 conv. code rate"; break;
            case 15: strm << "none"; break;
            default: strm << "code " << int(fec_inner) << " (reserved)"; break;
        }
        strm << std::endl;
    }

    display.displayExtraData(data, size, indent);
}