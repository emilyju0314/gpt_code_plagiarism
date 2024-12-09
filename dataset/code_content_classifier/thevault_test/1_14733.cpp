void write(uint16_t internal_address, uint8_t* data, uint8_t length) {
	if (length > 64) {
		_error("EEPROM_PAGE_WRITE::message exceeds 64 bytes.");
		return;
	}
	uint8_t upper_address = internal_address >> 8;
	uint8_t lower_address = internal_address & 0xFF;
	_start(I2C_ADDR_EEPROM, I2C_WRITE);
	_send_byte(upper_address);
	_send_byte(lower_address);
	while (length--) {
		_send_byte(*data++);
	}
	_stop();
}