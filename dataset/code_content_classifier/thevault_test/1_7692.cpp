void framebuffer_write() {
    // Sadly we can't do a single address and success data writes to efficiently
    // write the framebuffer data in one transaction.  Again the problem is
    // SPI word size and our limit of using 8-bit words.  The display buffer
    // data starts with a 14 bit alignment and then 4-bit words.  As a result
    // we just break down the framebuffer update into individual address writes.
    uint8_t i = 0;
    // Write out all 12 rows of the framebuffer.
    for (int r=0; r<12; r++) {
        // For each row write out the 4 columns, grabbing the appropriate nibble
        // of 4-bit data from the framebuffer.
        uint8_t address = r*4;
        ht1632_write(address,   framebuffer[i]);
        ht1632_write(address+1, framebuffer[i] >> 4);
        i += 1;
        ht1632_write(address+2, framebuffer[i]);
        ht1632_write(address+3, framebuffer[i] >> 4);
        i += 1;
    }
}