void ts::LinkageDescriptor::DisplayPrivateMobileHandover(TablesDisplay& display, const uint8_t*& data, size_t& size, int indent, uint8_t ltype)
{
    if (size < 1) {
        return;
    }

    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    uint8_t hand_over = *data >> 4;
    uint8_t origin = *data & 0x01;
    data += 1; size -= 1;

    const UChar *name;
    switch (hand_over) {
        case 0x01: name = u"identical service in neighbour country"; break;
        case 0x02: name = u"local variation of same service"; break;
        case 0x03: name = u"associated service"; break;
        default:   name = u"unknown"; break;
    }
    strm << margin << UString::Format(u"Hand-over type: 0x%X, %s, Origin: %s", {hand_over, name, origin ? u"SDT" : u"NIT"}) << std::endl;

    if ((hand_over == 0x01 || hand_over == 0x02 || hand_over == 0x03) && size >= 2) {
        uint16_t nwid = GetUInt16(data);
        data += 2; size -= 2;
        strm << margin << UString::Format(u"Network id: %d (0x%X)", {nwid, nwid}) << std::endl;
    }

    if (origin == 0x00 && size >= 2) {
        uint16_t org_servid = GetUInt16(data);
        data += 2; size -= 2;
        strm << margin << UString::Format(u"Original service id: %d (0x%X)", {org_servid, org_servid}) << std::endl;
    }
}