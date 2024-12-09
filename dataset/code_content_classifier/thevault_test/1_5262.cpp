void ts::TargetIPSlashDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    while (size >= 5) {
        strm << margin << "Address/mask: " << IPAddress(GetUInt32(data)) << "/" << int(data[4]) << std::endl;
        data += 5; size -= 5;
    }

    display.displayExtraData(data, size, indent);
}