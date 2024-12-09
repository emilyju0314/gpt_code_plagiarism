int8_t Bsec::spiTransfer(uint8_t devId, uint8_t regAddr, uint8_t *regData, uint16_t length)
{
	int8_t rslt = 0;
	if(Bsec::spiObj) {
		Bsec::spiObj->beginTransaction(SPISettings(4000000, MSBFIRST, SPI_MODE0)); // Can be upto 10MHz
	
		digitalWrite(devId, LOW);

		Bsec::spiObj->transfer(regAddr); // Write the register address, ignore the return
		for (uint16_t i = 0; i < length; i++)
			regData[i] = Bsec::spiObj->transfer(regData[i]);

		digitalWrite(devId, HIGH);
		Bsec::spiObj->endTransaction();
	} else {
		rslt = -1;
	}

	return rslt;;
}