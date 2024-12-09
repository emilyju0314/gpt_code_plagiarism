void Bsec::begin(uint8_t devId, enum bme680_intf intf, bme680_com_fptr_t read, bme680_com_fptr_t write, bme680_delay_fptr_t idleTask)
{
	_bme680.dev_id = devId;
	_bme680.intf = intf;
	_bme680.read = read;
	_bme680.write = write;
	_bme680.delay_ms = idleTask;
	_bme680.amb_temp = 25;
	_bme680.power_mode = BME680_FORCED_MODE;

	beginCommon();
}