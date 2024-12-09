static void ht1632_write(uint8_t address, uint8_t data) {
    // Like with writing a command we have to work with the 8-bit word
    // constraint of the hardware.  Luckily the HT1632C seems to ignore
    // trailing bits and we can send the 14 bit display data in a 16 bit word
    // (two bytes).
    // First chop off any unused bits from the address and data.
    address &= 0x7F;  // Address is 7 bits.
    data &= 0x0F;     // Data is 4 bits.
    // Construct write command.
    uint16_t write = HT1632_WRITE | ((uint16_t)address << 4) | data;
    write <<= 2;  // Shift up so command bits are at top.
    // Assert CS and send write command bytes.
    ASSERT_HT1632_CS;
    spi_master_write(&spi, (write >> 8) & 0xFF);
    spi_master_write(&spi, write & 0xFF);
    DEASSERT_HT1632_CS;
}