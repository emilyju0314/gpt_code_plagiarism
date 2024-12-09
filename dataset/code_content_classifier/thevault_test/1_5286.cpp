void ts::VBIDataDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    while (size >= 2) {
        const uint8_t data_id = data[0];
        size_t length = data[1];
        data += 2; size -= 2;
        if (length > size) {
            length = size;
        }
        strm << margin << "Data service id: " << NameFromSection(u"VBIDataServiceId", data_id, names::HEXA_FIRST) << std::endl;
        if (!EntryHasReservedBytes(data_id)) {
            while (length > 0) {
                const uint8_t field_parity = (data[0] >> 5) & 0x01;
                const uint8_t line_offset = data[0] & 0x1F;
                data++; size--; length--;
                strm << margin << "Field parity: " << int(field_parity) << ", line offset: " << int(line_offset) << std::endl;
            }
        }
        else if (length > 0) {
            strm << margin << "Associated data:" << std::endl
                << UString::Dump(data, length, UString::HEXA | UString::ASCII, indent);
            data += length; size -= length;
        }
    }

    display.displayExtraData(data, size, indent);
}