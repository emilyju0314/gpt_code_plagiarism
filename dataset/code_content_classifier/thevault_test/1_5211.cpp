void ts::DataStreamAlignmentDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    if (size >= 1) {
        strm << margin << "Alignment type: " << NameFromSection(u"DataStreamAlignment", data[0], names::BOTH_FIRST) << std::endl;
        data++; size--;
    }

    display.displayExtraData(data, size, indent);
}