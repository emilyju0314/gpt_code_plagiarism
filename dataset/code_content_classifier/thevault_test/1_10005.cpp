void _readBytesOTP(uint16_t address, byte data[]) {
			byte addressBytes[LEN_OTP_ADDR];
			
			// p60 - 6.3.3 Reading a value from OTP memory
			// bytes of address
			addressBytes[0] = (address & 0xFF);
			addressBytes[1] = ((address >> 8) & 0xFF);
			// set address
			_writeBytesToRegister(OTP_IF, OTP_ADDR_SUB, addressBytes, LEN_OTP_ADDR);
			// switch into read mode
			_writeSingleByteToRegister(OTP_IF, OTP_CTRL_SUB, 0x03); // OTPRDEN | OTPREAD
			_writeSingleByteToRegister(OTP_IF, OTP_CTRL_SUB, 0x01); // OTPRDEN
			// read value/block - 4 bytes
			_readBytesFromRegister(OTP_IF, OTP_RDAT_SUB, data, LEN_OTP_RDAT);
			// end read mode
			_writeSingleByteToRegister(OTP_IF, OTP_CTRL_SUB, 0x00);
		}