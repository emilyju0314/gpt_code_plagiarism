void foo::FooDescriptor::DisplayDescriptor(ts::TablesDisplay& display, ts::DID did, const uint8_t* payload, size_t size, int indent, ts::TID tid, ts::PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');
    strm << margin << "Name: \"" << display.duck().fromDVB(payload, size) << "\"" << std::endl;
}