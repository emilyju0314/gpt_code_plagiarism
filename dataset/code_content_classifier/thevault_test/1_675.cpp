uint8_t* BMP::get_pixel_ptr(const size_t& i) const {
    uint8_t bd = get_bit_depth();
    // Points to the row of this pixel
    uint8_t* row = get_row(i / get_width());
    // The offset from the beginning of the row to this pixel, NOT in bytes
    size_t offset = i % get_width();
    // offset * bd / 8 gives byte offset (e.g. 1 offset at 8 bit depth = 1 byte, 9 offset at 1 bit depth = 1 byte)
    return row + offset * bd / 8;
}