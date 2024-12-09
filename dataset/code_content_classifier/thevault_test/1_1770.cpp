void Bsec::begin(uint8_t chipSelect, SPIClass &spi)
{
	_bme680.dev_id = chipSelect;
	_bme680.intf = BME680_SPI_INTF;
	_bme680.read = Bsec::spiTransfer;
	_bme680.write = Bsec::spiTransfer;
	_bme680.delay_ms = Bsec::delay_ms;
	_bme680.amb_temp = 25;
	_bme680.power_mode = BME680_FORCED_MODE;

	pinMode(chipSelect, OUTPUT);
	digitalWrite(chipSelect, HIGH);
	Bsec::spiObj = &spi;
	Bsec::spiObj->begin();

	beginCommon();
}