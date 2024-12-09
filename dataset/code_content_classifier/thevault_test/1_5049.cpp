void ts::DVBStuffingDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');
    strm << margin << "Stuffing data, " << size << " bytes" << std::endl
         << UString::Dump(data, size, UString::HEXA | UString::ASCII | UString::OFFSET, indent);
}