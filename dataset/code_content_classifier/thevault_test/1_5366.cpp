void ts::LinkageDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    if (size >= 7) {

        // Fixed part
        uint16_t tsid = GetUInt16(data);
        uint16_t onid = GetUInt16(data + 2);
        uint16_t servid = GetUInt16(data + 4);
        uint8_t ltype = data[6];
        data += 7; size -= 7;
        strm << margin << UString::Format(u"Transport stream id: %d (0x%X)", {tsid, tsid}) << std::endl
             << margin << UString::Format(u"Original network Id: %d (0x%X)", {onid, onid}) << std::endl
             << margin << UString::Format(u"Service id: %d (0x%X)", {servid, servid}) << std::endl
             << margin << UString::Format(u"Linkage type: %s", {names::LinkageType(ltype, names::FIRST)}) << std::endl;

        // Variable part
        switch (ltype) {
            case 0x08:
                DisplayPrivateMobileHandover(display, data, size, indent, ltype);
                break;
            case 0x09:
                DisplayPrivateSSU(display, data, size, indent, ltype);
                break;
            case 0x0A:
                DisplayPrivateTableSSU(display, data, size, indent, ltype);
                break;
            case 0x0B:
                DisplayPrivateINT(display, data, size, indent, ltype);
                break;
            case 0x0C:
                DisplayPrivateDeferredINT(display, data, size, indent, ltype);
                break;
            default:
                break;
        }

        // Remaining private data
        if (size > 0) {
            strm << margin << "Private data:" << std::endl
                 << UString::Dump(data, size, UString::HEXA | UString::ASCII | UString::OFFSET, indent);
            data += size; size = 0;
        }
    }

    display.displayExtraData(data, size, indent);
}