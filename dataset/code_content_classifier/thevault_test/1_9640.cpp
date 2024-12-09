bool HumTransposer::setTransposition(const HumPitch &fromPitch, const string &toString) {
	HumPitch toPitch;
	if (getKeyTonic(toString, toPitch)) {
		// Determine proper octave offset.
		int numSigns = toPitch.getOctave();
		m_transpose = getInterval(fromPitch, toPitch);
		// A transposition with n plus or minus signs should never be more than n octaves away.
		if (numSigns > 0 && m_transpose > perfectOctaveClass() * numSigns) {
			m_transpose -= perfectOctaveClass();
		}
		else if (numSigns < 0 && m_transpose < perfectOctaveClass() * numSigns) {
			m_transpose += perfectOctaveClass();
		}
		// A transposition with 0 plus or minus signs should never be more than 1/2 an octave away.
		else if (numSigns == 0 && m_transpose > perfectOctaveClass() / 2) {
			m_transpose -= perfectOctaveClass();
		}
		else if (numSigns == 0 && m_transpose < -1 * perfectOctaveClass() / 2) {
			m_transpose += perfectOctaveClass();
		}
		return true;
	}
	return false;
}