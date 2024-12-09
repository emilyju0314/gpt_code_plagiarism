void ts::TablesLogger::preDisplay(PacketCounter first, PacketCounter last)
{
    std::ostream& strm(_display.duck().out());

    // Initial spacing
    if (_table_count == 0 && !_logger) {
        strm << std::endl;
    }

    // Display time stamp if required
    if ((_time_stamp || _packet_index) && !_logger) {
        strm << "* ";
        if (_time_stamp) {
            strm << "At " << Time::CurrentLocalTime();
        }
        if (_packet_index && _time_stamp) {
            strm << ", ";
        }
        if (_packet_index) {
            strm << UString::Format(u"First TS packet: %'d, last: %'d", {first, last});
        }
        strm << std::endl;
    }
}