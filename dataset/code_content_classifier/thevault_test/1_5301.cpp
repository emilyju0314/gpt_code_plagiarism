void ts::DataBroadcastIdDescriptor::DisplaySelectorINT(TablesDisplay& display, const uint8_t*& data, size_t& size, int indent, uint16_t dbid)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    // platform_id_data_length:
    if (size < 1) {
        return;
    }
    uint8_t dlength = data[0];
    data += 1; size -= 1;
    if (dlength > size) {
        dlength = uint8_t(size);
    }

    // Platform id loop.
    while (dlength >= 5) {
        strm << margin << UString::Format(u"- Platform id: %s", {ts::names::PlatformId(GetUInt24(data), names::HEXA_FIRST)}) << std::endl
             << margin << UString::Format(u"  Action type: 0x%X, version: ", {data[3]});
        if ((data[4] & 0x20) != 0) {
            strm << UString::Decimal(data[4] & 0x1F);
        }
        else {
            strm << "unspecified";
        }
        strm << std::endl;
        data += 5; size -= 5;  dlength -= 5;
    }

    // Extraneous data in Platform id loop:
    if (dlength > 0) {
        strm << margin << "Extraneous data in platform_id loop:" << std::endl
             << UString::Dump(data, dlength, UString::HEXA | UString::ASCII, indent);
        data += dlength; size -= dlength;
    }

    // Private data
    if (size > 0) {
        strm << margin << "Private data:" << std::endl
             << UString::Dump(data, size, UString::HEXA | UString::ASCII, indent);
        data += size; size = 0;
    }
}