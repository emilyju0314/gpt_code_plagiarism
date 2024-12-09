void ts::TargetMACAddressRangeDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    while (size >= 12) {
        strm << margin
             << "First address: " << MACAddress(GetUInt48(data))
             << ", last: " << MACAddress(GetUInt48(data + 6))
             << std::endl;
        data += 12; size -= 12;
    }

    display.displayExtraData(data, size, indent);
}