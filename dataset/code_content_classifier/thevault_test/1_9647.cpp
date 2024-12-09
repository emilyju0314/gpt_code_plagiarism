HumPitch HumTransposer::integerPitchToHumPitch(int ipitch) {
	HumPitch pitch;
	pitch.setOctave(ipitch / m_base);
	int chroma = ipitch - pitch.getOctave() * m_base;
	int mindiff = -1000;
	int mini = -1;

	int targetdiff = m_maxAccid;

	if (chroma > m_base / 2) {
		// search from B downwards
		mindiff = chroma - m_diatonicMapping.back();
		mini = (int)m_diatonicMapping.size() - 1;
		for (int i = (int)m_diatonicMapping.size() - 2; i >= 0; i--) {
			int diff = chroma - m_diatonicMapping[i];
			if (abs(diff) < abs(mindiff)) {
				mindiff = diff;
				mini = i;
			}
			if (abs(mindiff) <= targetdiff) {
				break;
			}
		}
	}
	else {
		// search from C upwards
		mindiff = chroma - m_diatonicMapping[0];
		mini = 0;
		for (int i = 1; i < (int)m_diatonicMapping.size(); i++) {
			int diff = chroma - m_diatonicMapping[i];
			if (abs(diff) < abs(mindiff)) {
				mindiff = diff;
				mini = i;
			}
			if (abs(mindiff) <= targetdiff) {
				break;
			}
		}
	}
	pitch.setDiatonicPC(mini);
	pitch.setAccid(mindiff);
	return pitch;
}