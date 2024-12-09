void ts::TargetIPv6SourceSlashDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    while (size >= 34) {
        strm << margin << "- Source:      " << IPv6Address(data, 16) << "/" << int(data[16]) << std::endl
             << margin << "  Destination: " << IPv6Address(data + 17, 16) << "/" << int(data[33]) << std::endl;
        data += 34; size -= 34;
    }

    display.displayExtraData(data, size, indent);
}