void DS1337::clearOSF() {
	readStatus();
	bitClear(_register[DS1337_STATUS], DS1337_OSF);
	writeStatus();
}