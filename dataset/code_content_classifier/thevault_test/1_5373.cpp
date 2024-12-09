bool ts::S2XSatelliteDeliverySystemDescriptor::deserializeChannel(Channel& channel, const uint8_t*& data, size_t& size)
{
    if (size < 11) {
        _is_valid = false;
        return false;
    }

    channel.frequency = uint64_t(DecodeBCD(data, 8)) * 10000;  // unit is 10 Hz
    channel.orbital_position = uint16_t(DecodeBCD(data + 4, 4));
    channel.east_not_west = (data[6] & 0x80) != 0;
    channel.polarization = (data[6] >> 5) & 0x03;
    channel.multiple_input_stream_flag = (data[6] & 0x10) != 0;
    channel.roll_off = (data[6] & 0x07);
    channel.symbol_rate = uint64_t(DecodeBCD(data + 7, 7, false)) * 100;  // unit is 100 sym/sec
    data += 11; size -= 11;

    return !channel.multiple_input_stream_flag || deserializeInt(channel.input_stream_identifier, data, size);
}