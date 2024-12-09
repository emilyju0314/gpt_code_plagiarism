float soundDevice::getGain() {
	float crntGain;

	alGetListenerf(AL_GAIN, &crntGain);
	return crntGain;
}