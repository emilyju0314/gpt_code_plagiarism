boolean Adafruit_TinyFlash::beginRead(uint32_t addr) {

	if((addr >= CHIP_BYTES) || !waitForReady()) return false;

	cmd(CMD_READDATA);
	(void)spi_xfer(addr >> 16);
	(void)spi_xfer(addr >>  8);
	(void)spi_xfer(addr      );
	// Chip is held in selected state until endRead()

	return true;
}