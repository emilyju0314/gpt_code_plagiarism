void ts::LinkageDescriptor::DisplayPrivateDeferredINT(TablesDisplay& display, const uint8_t*& data, size_t& size, int indent, uint8_t ltype)
{
    if (size >= 1) {
        std::ostream& strm(display.duck().out());
        const std::string margin(indent, ' ');

        uint8_t ttype = data[0];
        data += 1; size -= 1;

        strm << margin << "INT linkage table type: ";
        switch (ttype) {
            case 0x00: strm << "unspecified"; break;
            case 0x01: strm << "NIT"; break;
            case 0x02: strm << "BAT"; break;
            default:   strm << UString::Hexa(ttype); break;
        }
        strm << std::endl;

        if (ttype == 0x02 && size >= 2) {
            const uint16_t bid = GetUInt16(data);
            data += 2; size -= 2;
            strm << margin << UString::Format(u"Bouquet id: 0x%X (%d)", {bid, bid}) << std::endl;
        }
    }
}