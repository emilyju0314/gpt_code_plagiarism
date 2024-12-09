void ts::DCCT::DisplaySection(TablesDisplay& display, const ts::Section& section, int indent)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');
    const uint8_t* data = section.payload();
    size_t size = section.payloadSize();
    bool ok = true;

    if (size >= 2) {
        // Fixed part.
        const uint8_t subtype = uint8_t(section.tableIdExtension() >> 8);
        const uint8_t id = uint8_t(section.tableIdExtension());
        size_t dcc_test_count = data[1];
        strm << margin << UString::Format(u"DCC subtype: 0x%X (%d), DCC id: 0x%X (%d)", {subtype, subtype, id, id}) << std::endl
             << margin << UString::Format(u"Protocol version: %d, number of DCC tests: %d", {data[0], dcc_test_count}) << std::endl;
        data += 2; size -= 2;

        // Loop on all DCC tests.
        while (ok && dcc_test_count > 0) {

            // Check fixed part.
            ok = size >= 15;
            if (!ok) {
                break;
            }

            // Display fixed part.
            const uint8_t ctx = (data[0] >> 7) & 0x01;
            const uint32_t from = GetUInt24(data);
            const uint32_t to = GetUInt24(data + 3);
            const Time start(Time::GPSSecondsToUTC(GetUInt32(data + 6)));
            const Time end(Time::GPSSecondsToUTC(GetUInt32(data + 10)));
            size_t dcc_term_count = data[14];
            data += 15; size -= 15;

            strm << margin << UString::Format(u"- DCC context: %d (%s)", {ctx, DCCContextNames.name(ctx)}) << std::endl
                 << margin << UString::Format(u"  DCC from channel %d.%d to channel %d.%d", {(from >> 10) & 0x03FF, from & 0x03FF, (to >> 10) & 0x03FF, to & 0x03FF}) << std::endl
                 << margin << "  Start UTC: " << start.format(Time::DATETIME) << std::endl
                 << margin << "  End UTC:   " << end.format(Time::DATETIME) << std::endl
                 << margin << "  Number of DCC selection terms: " << dcc_term_count << std::endl;

            // Loop on all DCC selection terms.
            while (ok && dcc_term_count > 0) {

                // Check fixed part.
                ok = size >= 9;
                if (!ok) {
                    break;
                }

                // Display fixed part.
                strm << margin << "  - DCC selection type: " << NameFromSection(u"DCCSelectionType", data[0], names::FIRST) << std::endl
                     << margin << UString::Format(u"    DCC selection id: 0x%X", {GetUInt64(data + 1)}) << std::endl;
                data += 9; size -= 9;

                // Display descriptor list for this term.
                ok = ok && size >= 2;
                if (ok) {
                    size_t len = GetUInt16(data) & 0x03FF;
                    data += 2; size -= 2;
                    len = std::min(len, size);
                    if (len > 0) {
                        strm << margin << "    DCC selection term descriptors:" << std::endl;
                        display.displayDescriptorList(section, data, len, indent + 4);
                        data += len; size -= len;
                    }
                }

                dcc_term_count--;
            }

            // Display descriptor list for this DCC test.
            ok = ok && size >= 2;
            if (ok) {
                size_t len = GetUInt16(data) & 0x03FF;
                data += 2; size -= 2;
                len = std::min(len, size);
                if (len > 0) {
                    strm << margin << "  DCC test descriptors:" << std::endl;
                    display.displayDescriptorList(section, data, len, indent + 2);
                    data += len; size -= len;
                }
            }

            dcc_test_count--;
        }

        // Display descriptor list for the global table.
        if (ok && size >= 2) {
            size_t len = GetUInt16(data) & 0x03FF;
            data += 2; size -= 2;
            len = std::min(len, size);
            if (len > 0) {
                strm << margin << "Additional descriptors:" << std::endl;
                display.displayDescriptorList(section, data, len, indent);
                data += len; size -= len;
            }
        }
    }

    display.displayExtraData(data, size, indent);
}