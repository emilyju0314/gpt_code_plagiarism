void ts::IPMACGenericStreamLocationDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    if (size >= 7) {
        const uint16_t netid = GetUInt16(data);
        const uint8_t systype = GetUInt8(data + 2);
        const uint16_t sysid = GetUInt16(data + 3);
        const uint16_t strid  = GetUInt16(data + 5);
        strm << margin << UString::Format(u"Interactive network id: 0x%X (%d)", {netid, netid}) << std::endl
             << margin << UString::Format(u"Modulation system type: 0x%X (%s)", {systype, ModulationTypeNames.name(systype)}) << std::endl
             << margin << UString::Format(u"Modulation system id: 0x%X (%d)", {sysid, sysid}) << std::endl
             << margin << UString::Format(u"Physical stream id: 0x%X (%d)", {strid, strid}) << std::endl;
        if (size > 7) {
            strm << margin << "Selector bytes:" << std::endl
                 << UString::Dump(data + 7, size - 7, UString::HEXA | UString::ASCII | UString::OFFSET, indent);
        }
        data += size; size = 0;
    }

    display.displayExtraData(data, size, indent);
}