void Bsec::updateSubscription(bsec_virtual_sensor_t sensorList[], uint8_t nSensors, float sampleRate)
{
Serial.println("updSubs");
	bsec_sensor_configuration_t virtualSensors[BSEC_NUMBER_OUTPUTS],
	        sensorSettings[BSEC_MAX_PHYSICAL_SENSOR];
	uint8_t nVirtualSensors = 0, nSensorSettings = BSEC_MAX_PHYSICAL_SENSOR;

	for (uint8_t i = 0; i < nSensors; i++) {
		virtualSensors[nVirtualSensors].sensor_id = sensorList[i];
		virtualSensors[nVirtualSensors].sample_rate = sampleRate;
		nVirtualSensors++;
	}

	status = bsec_update_subscription(virtualSensors, nVirtualSensors, sensorSettings, &nSensorSettings);
Serial.println(".");
	return;
}