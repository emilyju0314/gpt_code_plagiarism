void ts::TargetIPAddressDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    const char* header = "Address mask: ";
    while (size >= 4) {
        strm << margin << header << IPAddress(GetUInt32(data)) << std::endl;
        data += 4; size -= 4;
        header = "Address: ";
    }

    display.displayExtraData(data, size, indent);
}