void ts::BitStream::reset(const void* data, size_t size_in_bits, size_t bit_offset_in_first_byte)
{
    _base = reinterpret_cast<const uint8_t*>(data) + (bit_offset_in_first_byte >> 3);
    _start_bit = bit_offset_in_first_byte & 0x07;
    _end_bit = _start_bit + size_in_bits;
    _next_bit = _start_bit;
}