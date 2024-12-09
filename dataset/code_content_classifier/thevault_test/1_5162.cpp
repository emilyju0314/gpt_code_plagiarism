void ts::DCCSCT::DisplaySection(TablesDisplay& display, const ts::Section& section, int indent)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');
    const uint8_t* data = section.payload();
    size_t size = section.payloadSize();

    if (size >= 2) {
        // Fixed part.
        size_t updates_defined = data[1];
        strm << margin << UString::Format(u"Protocol version: %d, DCCSCT type: 0x%X, number of updates: %d", {data[0], section.tableIdExtension(), updates_defined}) << std::endl;
        data += 2; size -= 2;

        // Loop on all update.
        while (updates_defined > 0 && size >= 2) {

            const uint8_t utype = data[0];
            size_t len = data[1];
            data += 2; size -= 2;

            strm << margin << UString::Format(u"- Update type: 0x%X (%s)", {utype, UpdateTypeNames.name(utype)}) << std::endl;

            if (size < len) {
                break;
            }

            // Display variable part.
            switch (utype) {
                case new_genre_category: {
                    if (len >= 1) {
                        strm << margin << UString::Format(u"  Genre category code: 0x%X (%d)", {data[0], data[0]}) << std::endl;
                        data++; size--;
                        ATSCMultipleString::Display(display, u"Genre category name: ", indent + 2, data, size, len - 1);
                    }
                    break;
                }
                case new_state: {
                    if (len >= 1) {
                        strm << margin << UString::Format(u"  DCC state location code: 0x%X (%d)", {data[0], data[0]}) << std::endl;
                        data++; size--;
                        ATSCMultipleString::Display(display, u"DCC state location: ", indent + 2, data, size, len - 1);
                    }
                    break;
                }
                case new_county: {
                    if (len >= 3) {
                        const uint16_t county = GetUInt16(data + 1) & 0x03FF;
                        strm << margin << UString::Format(u"  State code: 0x%X (%d), DCC county location code: 0x%03X (%d)", {data[0], data[0], county, county}) << std::endl;
                        data += 3; size -= 3;
                        ATSCMultipleString::Display(display, u"DCC county location: ", indent + 2, data, size, len - 3);
                    }
                    break;
                }
                default: {
                    display.displayExtraData(data, len, indent + 2);
                    data += len; size -= len;
                    break;
                }
            }

            // Display descriptor list for this update.
            if (size >= 2) {
                len = GetUInt16(data) & 0x03FF;
                data += 2; size -= 2;
                len = std::min(len, size);
                if (len > 0) {
                    strm << margin << "  Descriptors for this update:" << std::endl;
                    display.displayDescriptorList(section, data, len, indent + 2);
                    data += len; size -= len;
                }
            }

            updates_defined--;
        }

        // Display descriptor list for the global table.
        if (size >= 2) {
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