static void ht1632_command(uint8_t command) {
    // Construct full command as a 16-bit value.  This is actually not correct
    // because the hardware expects a 12-bit word, but the HAL / hardware
    // doesn't seem to support _anything_ besides 8-bit words (bytes).  Luckily
    // it appears the HT1632C ignores trailing bits so we can send a 16-bit
    // value (two bytes) with the 12-bit command shifted up to the most
    // significant bits.
    uint16_t full_command = HT1632_COMMAND | command;
    full_command <<= 5;  // Shift up so command bits are at top.
    // Assert CS and send command bytes.
    ASSERT_HT1632_CS;
    spi_master_write(&spi, (full_command >> 8) & 0xFF);
    spi_master_write(&spi, full_command & 0xFF);
    DEASSERT_HT1632_CS;
}