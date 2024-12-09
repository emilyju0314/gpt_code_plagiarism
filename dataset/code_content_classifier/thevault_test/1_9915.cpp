int32_t I2CReadReg24(int fd, uint8_t reg)
{
	if (write(fd, &reg, 1) != 1) {
		return -1;
	}

	int32_t data = 0;
	if (read(fd, &data, 3) != 3) {
		return -1;
	}
	return data;
}