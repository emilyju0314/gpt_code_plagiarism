void ts::EutelsatChannelNumberDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    while (size >= 8) {
        const uint16_t onetw_id = GetUInt16(data);
        const uint16_t ts_id = GetUInt16(data + 2);
        const uint16_t service_id = GetUInt16(data + 4);
        const uint16_t channel = GetUInt16(data + 6) & 0x0FFF;
        data += 8; size -= 8;
        strm << margin
             << UString::Format(u"Service Id: %5d (0x%04X), Channel number: %3d, TS Id: %5d (0x%04X), Net Id: %5d (0x%04X)",
                                {service_id, service_id, channel, ts_id, ts_id, onetw_id, onetw_id})
             << std::endl;
    }

    display.displayExtraData(data, size, indent);
}