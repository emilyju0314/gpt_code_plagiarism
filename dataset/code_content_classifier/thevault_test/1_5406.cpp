void ts::TDT::DisplaySection(TablesDisplay& display, const ts::Section& section, int indent)
{
    std::ostream& strm(display.duck().out());
    const uint8_t* data = section.payload();
    size_t size = section.payloadSize();

    if (size >= 5) {
        Time time;
        DecodeMJD(data, 5, time);
        data += 5; size -= 5;
        strm << std::string(indent, ' ') << "UTC time: " << time.format(Time::DATETIME) << std::endl;
    }

    display.displayExtraData(data, size, indent);
}