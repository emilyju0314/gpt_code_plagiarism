void ts::DataBroadcastIdDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    if (size >= 2) {
        uint16_t id = GetUInt16(data);
        data += 2; size -= 2;
        strm << margin << "Data broadcast id: " << names::DataBroadcastId(id, names::BOTH_FIRST) << std::endl;
        // The rest of the descriptor is the "id selector".
        DisplaySelectorBytes(display, data, size, indent, id);
        data += size; size = 0;
    }

    display.displayExtraData(data, size, indent);
}