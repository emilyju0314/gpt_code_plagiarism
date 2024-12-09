void ts::ATSCEIT::DisplaySection(TablesDisplay& display, const ts::Section& section, int indent)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');
    const uint8_t* data = section.payload();
    size_t size = section.payloadSize();
    const uint16_t sid = section.tableIdExtension();
    size_t event_count = size < 2 ? 0 : data[1];

    strm << margin << UString::Format(u"Source Id: 0x%X (%d)", {sid, sid}) << std::endl;

    if (size >= 2) {
        strm << margin << UString::Format(u"Protocol version: %d, number of events: %d", {data[0], data[1]}) << std::endl;
        data += 2; size -= 2;
    }

    // Get events description
    while (event_count > 0 && size >= 10) {

        const uint16_t evid = GetUInt16(data) & 0x3FFF;
        const Time start(Time::GPSSecondsToUTC(GetUInt32(data + 2)));
        const uint8_t loc = (data[6] >> 4) & 0x03;
        const uint32_t length = GetUInt24(data + 6) & 0x000FFFFF;
        const size_t title_length = data[9];
        data += 10; size -= 10;

        strm << margin << UString::Format(u"- Event Id: 0x%X (%d)", {evid, evid}) << std::endl
             << margin << "  Start UTC: " << start.format(Time::DATETIME) << std::endl
             << margin << UString::Format(u"  ETM location: %d", {loc}) << std::endl
             << margin << UString::Format(u"  Duration: %d seconds", {length}) << std::endl;

        ATSCMultipleString::Display(display, u"Title text: ", indent + 2, data, size, title_length);

        size_t info_length = GetUInt16(data) & 0x0FFF;
        data += 2; size -= 2;

        info_length = std::min(info_length, size);
        display.displayDescriptorList(section, data, info_length, indent + 2);
        data += info_length; size -= info_length;
        event_count--;
    }

    display.displayExtraData(data, size, indent);
}