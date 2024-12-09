void ts::SSUURIDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    if (size >= 2) {
        strm << margin << UString::Format(u"Max holdoff time: %d minutes", {data[0]}) << std::endl
             << margin << UString::Format(u"Min polling interval: %d hours", {data[1]}) << std::endl
             << margin << "URI: \"" << display.duck().fromDVB(data + 2, size - 2) << "\"" << std::endl;
    }
    else {
        display.displayExtraData(data, size, indent);
    }
}