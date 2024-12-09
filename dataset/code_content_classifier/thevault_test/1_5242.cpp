void ts::ApplicationRecordingDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    // Flags in first byte.
    bool valid = size >= 1;
    if (valid) {
        strm << margin << "Scheduled recording: " << UString::TrueFalse((data[0] & 0x80) != 0) << std::endl
             << margin << "Trick mode aware: " << UString::TrueFalse((data[0] & 0x40) != 0) << std::endl
             << margin << "Time shift: " << UString::TrueFalse((data[0] & 0x20) != 0) << std::endl
             << margin << "Dynamic: " << UString::TrueFalse((data[0] & 0x10) != 0) << std::endl
             << margin << "Av synced: " << UString::TrueFalse((data[0] & 0x08) != 0) << std::endl
             << margin << "Initiating replay: " << UString::TrueFalse((data[0] & 0x04) != 0) << std::endl;
        data++; size--;
    }

    // Labels
    valid = valid && size >= 1;
    if (valid) {
        uint8_t labelCount = data[0];
        data++; size--;
        while (valid && labelCount > 0) {
            valid = size >= 1 && size >= size_t(data[0] + 2);
            if (valid) {
                const size_t len = data[0];
                strm << margin << UString::Format(u"Label: \"%s\", storage properties: 0x%X", {display.duck().fromDVB(data + 1, len), uint8_t((data[len + 1] >> 6) & 0x03)}) << std::endl;
                data += len + 2;
                size -= len + 2;
                labelCount--;
            }
        }
        valid = valid && labelCount == 0;
    }

    // Component tags.
    valid = valid && size >= 1 && size >= size_t(1 + data[0]);
    if (valid) {
        uint8_t count = data[0];
        data++; size--;
        while (count > 0) {
            strm << margin << UString::Format(u"Component tag: 0x%X (%d)", {data[0], data[0]}) << std::endl;
            data++; size--;
            count--;
        }
    }

    // Private data.
    valid = valid && size >= 1 && size >= size_t(1 + data[0]);
    if (valid) {
        uint8_t count = data[0];
        data++; size--;
        if (count > 0) {
            strm << margin << "Private data:" << std::endl
                 << UString::Dump(data, count, UString::HEXA | UString::ASCII | UString::OFFSET, indent + 2);
        }
        data += count;
        size -= count;
    }

    if (valid && size > 0) {
        strm << margin << "Reserved bytes:" << std::endl
             << UString::Dump(data, size, UString::HEXA | UString::ASCII | UString::OFFSET, indent + 2);
        size = 0;
    }

    display.displayExtraData(data, size, indent);
}