void ts::DataBroadcastIdDescriptor::DisplaySelectorMPE(TablesDisplay& display, const uint8_t*& data, size_t& size, int indent, uint16_t dbid)
{
    // Fixed length: 2 bytes.
    if (size >= 2) {
        std::ostream& strm(display.duck().out());
        const std::string margin(indent, ' ');
        strm << margin << UString::Format(u"MAC address range: %d, MAC/IP mapping: %d, alignment: %d bits",
                                          {(data[0] >> 5) & 0x07, (data[0] >> 4) & 0x01, (data[0] & 0x08) == 0 ? 8 : 32})
             << std::endl
             << margin << UString::Format(u"Max sections per datagram: %d", {data[1]})
             << std::endl;
        data += 2; size -= 2;
    }
}