void Sensor::ECEZ0::calibrate(float lowuS, float highuS) {
	activate();
	// Clear calibrations
	writeReg(CALIBRATION_REQUEST_REGISTER, 0x01);
	delay(2000);
	// Do dry calibration
	writeReg(CALIBRATION_REQUEST_REGISTER, 0x02);
	// Wait 2 seconds
	delay(2000);

	auto valToSend = static_cast<unsigned>(lowuS * 100.f);
	std::vector<unsigned char> bytes(4);
	for (unsigned i = 0; i < 4; ++i) {
		bytes[3-i] = (valToSend >> (i * 8));
	}

	for (unsigned i = 0; i < 4; ++i) {
		writeReg(CALIBRATION_REGISTER_START + i, bytes[i]);
	}

	delay(2000);

	// Do low calibration
	writeReg(CALIBRATION_REQUEST_REGISTER, 0x04);

	delay(2000);

	// Write conductivity of high solution
	valToSend = static_cast<unsigned>(highuS * 100.f);
	for (unsigned i = 0; i < 4; ++i) {
		bytes[3-i] = (valToSend >> (i * 8));
	}

	for (unsigned i = 0; i < 4; ++i) {
		writeReg(CALIBRATION_REGISTER_START + i, bytes[i]);
	}
	delay(2000);
	// Do high calibration
	writeReg(CALIBRATION_REQUEST_REGISTER, 0x05);
	delay(1000);

	writeReg(MODE_REGISTER, 0x00);
	delay(1000);

	// Confirm
	auto v = readReg(CALIBRATION_CONFIRMATION_REGISTER);
	return;
}