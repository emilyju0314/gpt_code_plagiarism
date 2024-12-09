bool  Bsec::run(unsigned long int *ct)
{
	if(readPending)
		return true;
	bool newData = false;
	/* Check if the time has arrived to call do_steps() */
	int64_t callTimeMs = getTimeMs();
	*ct = callTimeMs;
	
	if (callTimeMs >= nextCall) {
	Serial.println("run");
	//	bsec_bme_settings_t bme680Settings;

		/*int64_t*/  callTimeNs = callTimeMs * INT64_C(1000000);

		status = bsec_sensor_control(callTimeNs, &bme680Settings);
		if (status < BSEC_OK) {
			return false;
Serial.println("f1");
}
		nextCall = bme680Settings.next_call / INT64_C(1000000); // Convert from ns to ms

		bme680Status = setBme680Config(bme680Settings);
		if (bme680Status != BME680_OK) {
			return false;
Serial.println("f2");
		}

		bme680Status = bme680_set_sensor_mode(&_bme680);
		if (bme680Status != BME680_OK) {
			return false;
Serial.println("f3");
		}

		/* Wait for measurement to complete */
		uint16_t meas_dur = 0;

		bme680_get_profile_dur(&meas_dur, &_bme680);
// callback can not be c++
//readPending = true;
//os_setTimedCallback(&readDatajob, os_getTime() + msec2osticks(meas_dur), readData);

		delay_ms(meas_dur);

		newData = readProcessData(callTimeNs, bme680Settings);	
Serial.println("." + String((long unsigned int)nextCall)); 
		return true;
	}
	
	return false;
}