void ts::CellListDescriptor::DisplayCoordinates(TablesDisplay& display, const uint8_t* data, size_t size, int indent)
{
    std::ostream& strm(display.duck().out());
    const std::string margin(indent, ' ');

    int32_t latitude = GetInt16(data);
    int32_t longitude = GetInt16(data + 2);
    uint32_t ext = GetUInt24(data + 4);
    uint16_t lat_ext = uint16_t(ext >> 12) & 0x0FFF;
    uint16_t long_ext = uint16_t(ext) & 0x0FFF;

    strm << margin << UString::Format(u"Raw latitude/longitude: %d/%d, extent: %d/%d", {latitude, longitude, lat_ext, long_ext}) << std::endl
         << margin << "Actual latitude range: " << ToDegrees(latitude, true) << " to " << ToDegrees(latitude + lat_ext, true) << std::endl
         << margin << "Actual longitude range: " << ToDegrees(longitude, false) << " to " << ToDegrees(longitude + long_ext, false) << std::endl;
}