void ts::CableEmergencyAlertTable::DisplaySection(TablesDisplay& display, const ts::Section& section, int indent)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');
    const uint8_t* data = section.payload();
    size_t size = section.payloadSize();
    bool ok = size >= 7;

    if (ok) {
        const uint8_t protocol_version = data[0];
        const uint16_t event_id = GetUInt16(data + 1);
        const UString orig_code(UString::FromUTF8(reinterpret_cast<const char*>(data + 3), 3));
        size_t len = data[6];
        data += 7; size -= 7;
        if (len > size) {
            len = size;
        }
        const UString event_code(UString::FromUTF8(reinterpret_cast<const char*>(data), len));
        data += len; size -= len;

        strm << margin << UString::Format(u"Protocol version: 0x%X (%d)", {protocol_version, protocol_version}) << std::endl
             << margin << UString::Format(u"EAS event id: 0x%X (%d)", {event_id, event_id}) << std::endl
             << margin << UString::Format(u"Originator code: \"%s\", event code: \"%s\"", {orig_code, event_code}) << std::endl;

        if (size > 0) {
            len = *data++;
            size--;
            ATSCMultipleString::Display(display, u"Nature of activation: ", indent, data, size, len);
        }

        ok = size >= 17;

        if (ok) {
            const uint8_t remaining = data[0];
            const uint32_t start_value = GetUInt32(data + 1);
            const Time start_time(Time::GPSSecondsToUTC(start_value));
            const uint16_t duration = GetUInt16(data + 5);
            const uint8_t priority = data[8] & 0x0F;
            const uint16_t details_oob = GetUInt16(data + 9);
            const uint16_t details_major = GetUInt16(data + 11) & 0x03FF;
            const uint16_t details_minor = GetUInt16(data + 13) & 0x03FF;
            const uint16_t audio_oob = GetUInt16(data + 15);
            data += 17; size -= 17;

            strm << margin
                 << UString::Format(u"Remaining: %d seconds, start time: %s, duration: %d minutes", {remaining, start_value == 0 ? u"immediate" : start_time.format(Time::DATETIME), duration})
                 << std::endl
                 << margin
                 << UString::Format(u"Alert priority: %d", {priority})
                 << std::endl
                 << margin
                 << UString::Format(u"Details: OOB id: 0x%X (%d), major.minor: %d.%d", {details_oob, details_oob, details_major, details_minor})
                 << std::endl
                 << margin
                 << UString::Format(u"Audio: OOB id: 0x%X (%d)", {audio_oob, audio_oob})
                 << std::endl;

            ok = size >= 2;
        }

        if (ok) {
            len = GetUInt16(data);
            data += 2; size -= 2;
            ATSCMultipleString::Display(display, u"Alert text: ", indent, data, size, len);
            ok = size >= 1;
        }

        if (ok) {
            // Display locations.
            len = *data++;
            size--;
            strm << margin << UString::Format(u"Number of locations: %d", {len}) << std::endl;
            while (ok && len-- > 0) {
                ok = size >= 3;
                if (ok) {
                    const uint8_t state = data[0];
                    const uint8_t subd = data[1] >> 4;
                    const uint16_t county = GetUInt16(data + 1) & 0x03FF;
                    strm << margin
                         << UString::Format(u"  State code: %d, county: %d, subdivision: %s", {state, county, NameFromSection(u"EASCountySubdivision", subd, names::VALUE)})
                         << std::endl;

                }
                data += 3; size -= 3;
            }
            ok = ok && size >= 1;
        }

        if (ok) {
            // Display exceptions.
            len = *data++;
            size--;
            strm << margin << UString::Format(u"Number of exceptions: %d", {len}) << std::endl;
            while (ok && len-- > 0) {
                ok = size >= 5;
                if (ok) {
                    const bool inband = (data[0] & 0x80) != 0;
                    strm << margin << UString::Format(u"  In-band: %s", {inband});
                    if (inband) {
                        strm << UString::Format(u", exception major.minor: %d.%d", {GetUInt16(data + 1) & 0x03FF, GetUInt16(data + 3) & 0x03FF}) << std::endl;
                    }
                    else {
                        strm << UString::Format(u", exception OOB id: 0x%X (%d)", {GetUInt16(data + 3), GetUInt16(data + 3)}) << std::endl;
                    }
                }
                data += 5; size -= 5;
            }
            ok = ok && size >= 2;
        }

        if (ok) {
            len = GetUInt16(data) & 0x03FF;
            data += 2; size -= 2;
            if (len > size) {
                len = size;
            }
            display.displayDescriptorList(section, data, len, indent);
            data += len; size -= len;
        }
    }

    display.displayExtraData(data, size, indent);
}