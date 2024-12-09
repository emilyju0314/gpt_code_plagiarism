void ts::TargetMACAddressDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    const char* header = "Address mask: ";
    while (size >= 6) {
        strm << margin << header << MACAddress(GetUInt48(data)) << std::endl;
        data += 6; size -= 6;
        header = "Address: ";
    }

    display.displayExtraData(data, size, indent);
}