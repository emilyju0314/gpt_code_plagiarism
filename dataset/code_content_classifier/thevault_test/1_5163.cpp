void ts::TargetIPSourceSlashDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    while (size >= 10) {
        strm << margin << "- Source:      " << IPAddress(GetUInt32(data)) << "/" << int(data[4]) << std::endl
             << margin << "  Destination: " << IPAddress(GetUInt32(data + 5)) << "/" << int(data[9]) << std::endl;
        data += 10; size -= 10;
    }

    display.displayExtraData(data, size, indent);
}