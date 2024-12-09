void ts::DVBJApplicationDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    while (size >= 1) {
        const size_t len = std::min<size_t>(data[0], size - 1);
        strm << margin << "Parameter: \"" << display.duck().fromDVB(data + 1, len) << "\"" << std::endl;
        data += 1 + len; size -= 1 + len;
    }

    display.displayExtraData(data, size, indent);
}