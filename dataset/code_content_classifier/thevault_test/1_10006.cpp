void _vbatAndTempSteps() {
			byte step1 = 0x80; _writeBytesToRegister(RF_CONF, 0x11, &step1, 1);
			byte step2 = 0x0A; _writeBytesToRegister(RF_CONF, 0x12, &step2, 1);
			byte step3 = 0x0F; _writeBytesToRegister(RF_CONF, 0x12, &step3, 1);
			byte step4 = 0x01; _writeBytesToRegister(TX_CAL, NO_SUB, &step4, 1);
			byte step5 = 0x00; _writeBytesToRegister(TX_CAL, NO_SUB, &step5, 1);
		}