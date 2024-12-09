int HumTransposer::circleOfFifthsToIntervalClass(int fifths) {
	if (fifths == 0) {
		return 0;
	}
	else if (fifths > 0) {
		return (perfectFifthClass() * fifths) % m_base;
	}
	else {
		return (perfectFourthClass() * (-fifths)) % m_base;
	}
}