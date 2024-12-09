bool framebuffer_get(uint8_t x, uint8_t y) {
    // Ignore values that are out of bounds of the 12x12 portion of display.
    if ((x > 11) || (y > 11)) {
      return false;
    }
    // Calculate bit position of this pixel within framebuffer.
    uint8_t bit = y*16+x;
    uint8_t byte_pos = bit / 8;
    uint8_t byte_offset = bit % 8;
    // Invert position within each 4 bit nibble to match order of bits for
    // HT1632 display memory.
    if (byte_offset < 4) {
        // 0 1 2 3 -> 3 2 1 0
        byte_offset = 3 - byte_offset;
    }
    else {
        // 4 5 6 7 -> 7 6 5 4
        byte_offset = 11 - byte_offset;
    }
    // Check if the bit at the pixel position is set.
    return (framebuffer[byte_pos] & (1 << byte_offset)) > 0;
}