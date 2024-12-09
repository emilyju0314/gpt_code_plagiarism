void ts::IPSignallingDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    if (size >= 3) {
        strm << margin << "Platform id: " << names::PlatformId(GetUInt24(data), names::FIRST) << std::endl;
        data += 3; size -= 3;
    }

    display.displayExtraData(data, size, indent);
}