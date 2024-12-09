void ts::S2XSatelliteDeliverySystemDescriptor::serializeChannel(const Channel& channel, ByteBlock& bb) const
{
    bb.appendBCD(uint32_t(channel.frequency / 10000), 8);  // unit is 10 kHz
    bb.appendBCD(channel.orbital_position, 4);
    bb.appendUInt8((channel.east_not_west ? 0x80 : 0x00) |
                   uint8_t((channel.polarization & 0x03) << 5) |
                   (channel.multiple_input_stream_flag ? 0x10 : 0x00) |
                   (channel.roll_off & 0x07));
    bb.appendBCD(uint32_t(channel.symbol_rate / 100), 7, false); // unit is 100 sym/s 
    if (channel.multiple_input_stream_flag) {
        bb.appendUInt8(channel.input_stream_identifier);
    }
}