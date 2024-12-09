void ts::ServiceLocationDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    if (size >= 3) {
        std::ostream& strm(display.duck().out());
        const std::string margin(indent, ' ');

        PID pid = GetUInt16(data) & 0x1FFF;
        size_t count = data[2];
        data += 3; size -= 3;

        strm << margin << "PCR PID: ";
        if (pid == PID_NULL) {
            strm << "none";
        }
        else {
            strm << UString::Format(u"0x%X (%d)", {pid, pid});
        }
        strm << ", number of elements: " << count << std::endl;

        // Loop on all component entries.
        while (count-- > 0 && size >= 6) {
            const uint8_t stype = data[0];
            pid = GetUInt16(data + 1) & 0x1FFF;
            const UString lang(DeserializeLanguageCode(data + 3));
            data += 6; size -= 6;

            strm << margin << UString::Format(u"- PID: 0x%X (%d), language: \"%s\", type: %s", {pid, pid, lang, names::ServiceType(stype, names::FIRST)}) << std::endl;
        }
    }

    display.displayExtraData(data, size, indent);
}