void ts::STDDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    if (size >= 1) {
        uint8_t leak = data[0] & 0x01;
        data += 1; size -= 1;
        strm << margin << "Link valid flag: " << int(leak)
             << (leak != 0 ? " (leak)" : " (vbv_delay)") << std::endl;
    }

    display.displayExtraData(data, size, indent);
}