void ts::TransportStreamDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* payload, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');
    strm << margin << "Compliance: \"" << display.duck().fromDVB(payload, size) << "\"" << std::endl;
}