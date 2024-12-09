static u16 do_crc(BYTE *data, DWORD data_len, u16 crc)
{
	for (DWORD i = 0; i < data_len; ++i) {
		crc ^= data[i] << 8;
		for (DWORD k = 0; k < 8; ++k)
			if (crc & 0x8000)
				crc = (crc << 1) ^ 0x1021;
			else
				crc <<= 1;
	}

	return crc;
}