int8_t Bsec::setBme680Config(bsec_bme_settings_t bme680Settings)
{
	_bme680.gas_sett.run_gas = bme680Settings.run_gas;
	_bme680.tph_sett.os_hum = bme680Settings.humidity_oversampling;
	_bme680.tph_sett.os_temp = bme680Settings.temperature_oversampling;
	_bme680.tph_sett.os_pres = bme680Settings.pressure_oversampling;
	_bme680.gas_sett.heatr_temp = bme680Settings.heater_temperature;
	_bme680.gas_sett.heatr_dur = bme680Settings.heating_duration;
	uint16_t desired_settings = BME680_OST_SEL | BME680_OSP_SEL | BME680_OSH_SEL | BME680_FILTER_SEL
	        | BME680_GAS_SENSOR_SEL;
	return bme680_set_sensor_settings(desired_settings, &_bme680);
}