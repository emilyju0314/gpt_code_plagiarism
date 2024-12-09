uint8_t read(uint16_t internal_address) {
	uint8_t buf;
	uint8_t upper_address = internal_address >> 8;
	uint8_t lower_address = internal_address & 0xFF;
	_start(I2C_ADDR_EEPROM, I2C_WRITE);
	_send_byte(upper_address);
	_send_byte(lower_address);
	_start(I2C_ADDR_EEPROM, I2C_READ);
	buf = _read_byte(false);
	_stop();
	return buf;
}