void Bsec::zeroOutputs(void)
{
	temperature = 0.0f;
	pressure = 0.0f;
	humidity = 0.0f;
	gasResistance = 0.0f;
	rawTemperature = 0.0f;
	rawHumidity = 0.0f;
	stabStatus = 0.0f;
	runInStatus = 0.0f;
	iaqEstimate = 0.0f;
	iaqAccuracy = 0;
	staticIaq = 0.0f;
	staticIaqAccuracy = 0;
	co2Equivalent = 0.0f;
	co2Accuracy = 0;
	breathVocEquivalent = 0.0f;
	breathVocAccuracy = 0;
	compGasValue = 0.0f;
	compGasAccuracy = 0;
	gasPercentage = 0.0f;
	gasPercentageAcccuracy = 0;
}