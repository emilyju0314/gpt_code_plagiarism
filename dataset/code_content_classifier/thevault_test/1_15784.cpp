boolean Adafruit_TinyFlash::writePage(uint32_t addr, uint8_t *data) {
	if((addr >= CHIP_BYTES) || !waitForReady() || !writeEnable())
		return false;

	cmd(CMD_PAGEPROG);
	(void)spi_xfer(addr >> 16);
	(void)spi_xfer(addr >>  8);
	(void)spi_xfer(0); // If len=256, page boundary only (datasheet 7.2.21)
	for(int i=0; i<256; i++) {
		(void)spi_xfer(data[i]);
	}
	CHIP_DESELECT // Write occurs after the CS line is de-asserted

	delay(3);     // Max page program time according to datasheet

	if(!waitForReady()) return false;

	writeDisable();

	return true;
}