void ts::DVBEnhancedAC3Descriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    if (size >= 1) {
        uint8_t flags = data[0];
        data++; size--;

        if ((flags & 0x80) && size >= 1) { // component_type
            uint8_t type = data[0];
            data++; size--;
            strm << margin << "Component type: " << names::AC3ComponentType(type, names::FIRST) << std::endl;
        }
        if ((flags & 0x40) && size >= 1) { // bsid
            uint8_t bsid = data[0];
            data++; size--;
            strm << margin << UString::Format(u"AC-3 coding version: %d (0x%X)", {bsid, bsid}) << std::endl;
        }
        if ((flags & 0x20) && size >= 1) { // mainid
            uint8_t mainid = data[0];
            data++; size--;
            strm << margin << UString::Format(u"Main audio service id: %d (0x%X)", {mainid, mainid}) << std::endl;
        }
        if ((flags & 0x10) && size >= 1) { // asvc
            uint8_t asvc = data[0];
            data++; size--;
            strm << margin << UString::Format(u"Associated to: 0x%X", {asvc}) << std::endl;
        }
        if (flags & 0x08) {
            strm << margin << "Substream 0: Mixing control metadata" << std::endl;
        }
        if ((flags & 0x04) && size >= 1) { // substream1
            uint8_t type = data[0];
            data++; size--;
            strm << margin << "Substream 1: " << names::AC3ComponentType(type, names::FIRST) << std::endl;
        }
        if ((flags & 0x02) && size >= 1) { // substream2
            uint8_t type = data[0];
            data++; size--;
            strm << margin << "Substream 2: " << names::AC3ComponentType(type, names::FIRST) << std::endl;
        }
        if ((flags & 0x01) && size >= 1) { // substream3
            uint8_t type = data[0];
            data++; size--;
            strm << margin << "Substream 3: " << names::AC3ComponentType(type, names::FIRST) << std::endl;
        }
        if (size > 0) {
            strm << margin << "Additional information:" << std::endl
                 << UString::Dump(data, size, UString::HEXA | UString::ASCII | UString::OFFSET, indent);
            data += size; size = 0;
        }
    }

    display.displayExtraData(data, size, indent);
}