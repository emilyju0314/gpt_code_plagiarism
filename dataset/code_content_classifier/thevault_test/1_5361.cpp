void ts::NetworkChangeNotifyDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    // Important: With extension descriptors, the DisplayDescriptor() function is called
    // with extension payload. Meaning that data points after descriptor_tag_extension.
    // See ts::TablesDisplay::displayDescriptorData()

    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');
    bool ok = true;

    while (ok && size >= 3) {
        strm << margin << UString::Format(u"- Cell id: 0x%X", {GetUInt16(data)}) << std::endl;
        size_t len = data[2];
        data += 3; size -= 3;

        while (ok && size >= len && len >= 12) {
            Time start;
            DecodeMJD(data + 2, 5, start);
            strm << margin
                 << UString::Format(u"  - Network change id: 0x%X, version: 0x%X", {data[0], data[1]}) 
                 << std::endl
                 << margin
                 << UString::Format(u"    Start: %s, duration: %02d:%02d:%02d", {start.format(Time::DATE | Time::TIME), DecodeBCD(data[7]), DecodeBCD(data[8]), DecodeBCD(data[9])})
                 << std::endl
                 << margin
                 << UString::Format(u"    Receiver category: 0x%X", {uint8_t((data[10] >> 5) & 0x07)})
                 << std::endl
                 << margin
                 << "    Change type: " << NameFromSection(u"NetworkChangeType", data[10] & 0x0F, names::HEXA_FIRST)
                 << std::endl
                 << margin
                 << UString::Format(u"    Message id: 0x%X", {data[11]})
                 << std::endl;
            const bool invariant_ts_present = (data[10] & 0x10) != 0;
            data += 12; size -= 12; len -= 12;
            if (invariant_ts_present) {
                ok = len >= 4;
                if (ok) {
                    strm << margin
                         << UString::Format(u"    Invariant TS id: 0x%X, orig. net. id: 0x%X", {GetUInt16(data), GetUInt16(data + 2)}) 
                         << std::endl;
                    data += 4; size -= 4; len -= 4;
                }
            }
        }
        ok = ok && len == 0;
    }

    display.displayExtraData(data, size, indent);
}