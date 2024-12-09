void soundDevice::setGain(float value) {

	//clamp between 0 - 5 because i dont like blown speakers
	float newVolume = value;
	if (newVolume < 0.0f) {
		newVolume = 0.0f;
		cout << "ERROR: GAIN MINIMUM LIMIT REACHED" << endl;
	}
	else if (newVolume > 5.0f) {
		newVolume = 5.0f;
		cout << "ERROR: GAIN MAXIMUM LIMIT REACHED" << endl;
	}
}