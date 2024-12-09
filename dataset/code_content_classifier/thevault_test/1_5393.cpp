void ts::CellListDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    while (size >= 10) {
        strm << margin << UString::Format(u"- Cell id: 0x%X (%d)", {GetUInt16(data), GetUInt16(data)}) << std::endl;
        DisplayCoordinates(display, data + 2, size - 2, indent + 2);
        size_t len = data[9];
        data += 10; size -= 10;

        while (size >= len && len >= 8) {
            strm << margin << UString::Format(u"  - Subcell id ext: 0x%X (%d)", {data[0], data[0]}) << std::endl;
            DisplayCoordinates(display, data + 1, size - 1, indent + 4);
            data += 8; size -= 8; len -= 8;
        }
        if (len > 0) {
            break;
        }
    }

    display.displayExtraData(data, size, indent);
}