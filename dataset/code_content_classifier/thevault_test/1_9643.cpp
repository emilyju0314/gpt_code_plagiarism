int HumTransposer::intervalToSemitones(int interval) {
	int sign = interval < 0 ? -1 : +1;
	interval = interval < 0 ? -interval : interval;
	int octave = interval / m_base;
	int intervalClass = interval - octave * m_base;
	int diatonic = 0;
	int chromatic = 0;
	intervalToDiatonicChromatic(diatonic, chromatic, intervalClass);
	if ((diatonic != INVALID_INTERVAL_CLASS) && (chromatic != INVALID_INTERVAL_CLASS)) {
		return (m_diatonic2semitone.at(diatonic) + chromatic) * sign + 12 * octave;
	}
	else {
		return INVALID_INTERVAL_CLASS;
	}
}