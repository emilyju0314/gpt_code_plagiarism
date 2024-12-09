void ts::LocalTimeOffsetDescriptor::DisplayDescriptor(TablesDisplay& display, DID did, const uint8_t* data, size_t size, int indent, TID tid, PDS pds)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    while (size >= 3) {
        // Country code is a 3-byte string
        strm << margin << "Country code: " << DeserializeLanguageCode(data) << std::endl;
        data += 3; size -= 3;
        if (size >= 1) {
            uint8_t region_id = *data >> 2;
            uint8_t polarity = *data & 0x01;
            data += 1; size -= 1;
            strm << margin
                 << UString::Format(u"Region id: %d (0x%X), polarity: %s of Greenwich", {region_id, region_id, polarity ? u"west" : u"east"})
                 << std::endl;
            if (size >= 2) {
                strm << margin
                     << UString::Format(u"Local time offset: %s%02d:%02d", {polarity ? u"-" : u"", DecodeBCD(data[0]), DecodeBCD(data[1])})
                     << std::endl;
                data += 2; size -= 2;
                if (size >= 5) {
                    Time next_change;
                    DecodeMJD(data, 5, next_change);
                    data += 5; size -= 5;
                    strm << margin << "Next change: " << next_change.format(Time::DATETIME) << std::endl;
                    if (size >= 2) {
                        strm << margin
                             << UString::Format(u"Next time offset: %s%02d:%02d", {polarity ? u"-" : u"", DecodeBCD(data[0]), DecodeBCD(data[1])})
                             << std::endl;
                        data += 2; size -= 2;
                    }
                }
            }
        }
    }

    display.displayExtraData(data, size, indent);
}