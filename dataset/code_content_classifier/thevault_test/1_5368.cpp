void ts::LinkageDescriptor::DisplayPrivateSSU(TablesDisplay& display, const uint8_t*& data, size_t& size, int indent, uint8_t ltype)
{
    if (size < 1) {
        return;
    }

    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    uint8_t dlength = data[0];
    data += 1; size -= 1;
    if (dlength > size) {
        dlength = uint8_t(size);
    }

    while (dlength >= 4) {
        uint32_t oui = GetUInt24(data);
        uint8_t slength = data[3];
        data += 4; size -= 4; dlength -= 4;
        const uint8_t* sdata = data;
        if (slength > dlength) {
            slength = dlength;
        }
        data += slength; size -= slength; dlength -= slength;
        strm << margin << "OUI: " << names::OUI(oui, names::FIRST) << std::endl;
        if (slength > 0) {
            strm << margin << "Selector data:" << std::endl
                 << UString::Dump(sdata, slength, UString::HEXA | UString::ASCII, indent);
        }
    }
}