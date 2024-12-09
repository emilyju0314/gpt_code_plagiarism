void DS1337::resetTick() {
	readStatus();
	bitClear(_register[DS1337_STATUS], DS1337_A2F);
	writeStatus();
}