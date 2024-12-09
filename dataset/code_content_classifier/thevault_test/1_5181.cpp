void ts::MPEG2AACAudioDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    if (size >= 3) {
        strm << margin << UString::Format(u"MPEG-2 AAC profile: 0x%X (%d)", {data[0], data[0]}) << std::endl
             << margin << UString::Format(u"MPEG-2 AAC channel configuration: 0x%X (%d)", {data[1], data[1]}) << std::endl
             << margin << UString::Format(u"MPEG-2 AAC additional information: 0x%X (%d)", {data[2], data[2]}) << std::endl;
        data += 3; size -= 3;
    }

    display.displayExtraData(data, size, indent);
}