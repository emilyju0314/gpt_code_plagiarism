bool Bsec::readProcessData(int64_t currTimeNs, bsec_bme_settings_t bme680Settings)
{
	bme680Status = bme680_get_sensor_data(&_data, &_bme680);
	if (bme680Status != BME680_OK) {
		return false;
	}

	bsec_input_t inputs[BSEC_MAX_PHYSICAL_SENSOR]; // Temp, Pres, Hum & Gas
	uint8_t nInputs = 0, nOutputs = 0;

	if (_data.status & BME680_NEW_DATA_MSK) {
		if (bme680Settings.process_data & BSEC_PROCESS_TEMPERATURE) {
			inputs[nInputs].sensor_id = BSEC_INPUT_TEMPERATURE;
			inputs[nInputs].signal = _data.temperature;
			inputs[nInputs].time_stamp = currTimeNs;
			nInputs++;
			/* Temperature offset from the real temperature due to external heat sources */
			inputs[nInputs].sensor_id = BSEC_INPUT_HEATSOURCE;
			inputs[nInputs].signal = _tempOffset;
			inputs[nInputs].time_stamp = currTimeNs;
			nInputs++;
		}
		if (bme680Settings.process_data & BSEC_PROCESS_HUMIDITY) {
			inputs[nInputs].sensor_id = BSEC_INPUT_HUMIDITY;
			inputs[nInputs].signal = _data.humidity;
			inputs[nInputs].time_stamp = currTimeNs;
			nInputs++;
		}
		if (bme680Settings.process_data & BSEC_PROCESS_PRESSURE) {
			inputs[nInputs].sensor_id = BSEC_INPUT_PRESSURE;
			inputs[nInputs].signal = _data.pressure;
			inputs[nInputs].time_stamp = currTimeNs;
			nInputs++;
		}
		if (bme680Settings.process_data & BSEC_PROCESS_GAS) {
			inputs[nInputs].sensor_id = BSEC_INPUT_GASRESISTOR;
			inputs[nInputs].signal = _data.gas_resistance;
			inputs[nInputs].time_stamp = currTimeNs;
			nInputs++;
		}
	}

	if (nInputs > 0) {
		nOutputs = BSEC_NUMBER_OUTPUTS;
		bsec_output_t _outputs[BSEC_NUMBER_OUTPUTS];

		status = bsec_do_steps(inputs, nInputs, _outputs, &nOutputs);
		if (status != BSEC_OK)
			return false;

		zeroOutputs();

		if (nOutputs > 0) {
			outputTimestamp = _outputs[0].time_stamp / 1000000; // Convert from ns to ms

			for (uint8_t i = 0; i < nOutputs; i++) {
				switch (_outputs[i].sensor_id) {
					case BSEC_OUTPUT_IAQ:
						iaqEstimate = _outputs[i].signal;
						iaqAccuracy = _outputs[i].accuracy;
						break;
					case BSEC_OUTPUT_STATIC_IAQ:
						staticIaq = _outputs[i].signal;
						staticIaqAccuracy = _outputs[i].accuracy;
						break;
					case BSEC_OUTPUT_CO2_EQUIVALENT:
						co2Equivalent = _outputs[i].signal;
						co2Accuracy = _outputs[i].accuracy;
						break;
					case BSEC_OUTPUT_BREATH_VOC_EQUIVALENT:
						breathVocEquivalent = _outputs[i].signal;
						breathVocAccuracy = _outputs[i].accuracy;
						break;
					case BSEC_OUTPUT_RAW_TEMPERATURE:
						rawTemperature = _outputs[i].signal;
						break;
					case BSEC_OUTPUT_RAW_PRESSURE:
						pressure = _outputs[i].signal;
						break;
					case BSEC_OUTPUT_RAW_HUMIDITY:
						rawHumidity = _outputs[i].signal;
						break;
					case BSEC_OUTPUT_RAW_GAS:
						gasResistance = _outputs[i].signal;
						break;
					case BSEC_OUTPUT_STABILIZATION_STATUS:
						stabStatus = _outputs[i].signal;
						break;
					case BSEC_OUTPUT_RUN_IN_STATUS:
						runInStatus = _outputs[i].signal;
						break;
					case BSEC_OUTPUT_SENSOR_HEAT_COMPENSATED_TEMPERATURE:
						temperature = _outputs[i].signal;
						break;
					case BSEC_OUTPUT_SENSOR_HEAT_COMPENSATED_HUMIDITY:
						humidity = _outputs[i].signal;
						break;
					case BSEC_OUTPUT_COMPENSATED_GAS:
						compGasValue = _outputs[i].signal;
						compGasAccuracy = _outputs[i].accuracy;
						break;
					case BSEC_OUTPUT_GAS_PERCENTAGE:
						gasPercentage = _outputs[i].signal;
						gasPercentageAcccuracy = _outputs[i].accuracy;
						break;
					default:
						break;
				}
			}
			return true;
		}
	}

	return false;
}