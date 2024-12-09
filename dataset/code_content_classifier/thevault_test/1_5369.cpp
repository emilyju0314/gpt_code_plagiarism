void ts::LinkageDescriptor::DisplayPrivateTableSSU(TablesDisplay& display, const uint8_t*& data, size_t& size, int indent, uint8_t ltype)
{
    if (size >= 1) {
        std::ostream& strm(display.duck().out());
        const std::string margin(indent, ' ');

        uint8_t ttype = data[0];
        data += 1; size -= 1;

        strm << margin << "SSU table type: ";
        switch (ttype) {
            case 0x01: strm << "NIT"; break;
            case 0x02: strm << "BAT"; break;
            default:   strm << UString::Hexa(ttype); break;
        }
        strm << std::endl;
    }
}