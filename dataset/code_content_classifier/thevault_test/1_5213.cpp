uint8_t ts::BitStream::readBit(uint8_t def)
{
    if (_next_bit >= _end_bit) {
        return def;
    }
    else {
        const uint8_t b = (_base[_next_bit >> 3] >> (7 - (_next_bit & 0x07))) & 0x01;
        _next_bit++;
        return b;
    }
}