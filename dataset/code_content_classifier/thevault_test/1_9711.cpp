std::string HumPitch::getScientificPitch(void) const {
	if (m_diatonicpc < 0) {
		return "R";
	}
	string output;
	output = m_diatonicPC2letterUC.at(m_diatonicpc);
	if (m_accid < 0) {
		for (int i=0; i<-m_accid; i++) {
			output += 'b';
		}
	} else if (m_accid > 0) {
		for (int i=0; i<m_accid; i++) {
			output += '#';
		}
	}
	output = to_string(m_oct);
	return output;
}