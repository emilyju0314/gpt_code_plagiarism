void ts::ServiceAvailabilityDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    if (size >= 1) {
        strm << margin << "Availability: " << UString::TrueFalse((data[0] & 0x80) != 0) << std::endl;
        data++; size--;
        while (size >= 2) {
            const uint16_t id = GetUInt16(data);
            data += 2; size -= 2;
            strm << margin << UString::Format(u"Cell id: 0x%X (%d)", {id, id}) << std::endl;
        }
    }

    display.displayExtraData(data, size, indent);
}