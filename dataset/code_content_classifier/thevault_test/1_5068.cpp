void ts::ECMRepetitionRateDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    if (size >= 4) {
        strm << margin << UString::Format(u"CA System Id: %s", {names::CASId(GetUInt16(data), names::FIRST)}) << std::endl
             << margin << UString::Format(u"ECM repetition rate: %d ms", {GetUInt16(data + 2)}) << std::endl;
        data += 4; size -= 4;
        if (size > 0) {
            strm << margin << "Private data:" << std::endl
                 << UString::Dump(data, size, UString::HEXA | UString::ASCII | UString::OFFSET, indent);
            data += size; size = 0;
        }
    }

    display.displayExtraData(data, size, indent);
}