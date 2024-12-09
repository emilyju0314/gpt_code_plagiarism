void ts::SpliceTimeDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    if (size >= 16) {
        const uint64_t tai = GetUInt48(data + 4);
        const uint32_t ns = GetUInt32(data + 10);
        const uint16_t off = GetUInt16(data + 14);
        strm << margin << UString::Format(u"Identifier: 0x%X", {GetUInt32(data)});
        display.duck().displayIfASCII(data, 4, u" (\"", u"\")");
        strm << std::endl
             << margin
             << UString::Format(u"TAI: %'d seconds (%s) + %'d ns, UTC offset: %'d", {tai, Time::UnixTimeToUTC(uint32_t(tai)).format(Time::DATE | Time::TIME), ns, off})
             << std::endl;
        data += 16; size -= 16;
    }

    display.displayExtraData(data, size, indent);
}