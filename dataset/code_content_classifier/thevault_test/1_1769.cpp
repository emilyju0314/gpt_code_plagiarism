void Bsec::begin(uint8_t i2cAddr, TwoWire &i2c)
{
	_bme680.dev_id = i2cAddr;
	_bme680.intf = BME680_I2C_INTF;
	_bme680.read = Bsec::i2cRead;
	_bme680.write = Bsec::i2cWrite;
	_bme680.delay_ms = Bsec::delay_ms;
	_bme680.amb_temp = 25;
	_bme680.power_mode = BME680_FORCED_MODE;

	Bsec::wireObj = &i2c;
	Bsec::wireObj->begin();

	beginCommon();
}