void ts::AncillaryDataDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    if (size >= 1) {
        uint8_t id = data[0];
        data += 1; size -= 1;
        strm << margin << UString::Format(u"Ancillary data identifier: 0x%X", {id}) << std::endl;
        for (int i = 0; i < 8; ++i) {
            if ((id & (1 << i)) != 0) {
                strm << margin << "  " << NameFromSection(u"AncillaryDataIdentifier", (1 << i), names::HEXA_FIRST) << std::endl;
            }
        }
    }

    display.displayExtraData(data, size, indent);
}