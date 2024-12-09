void HumTransposer::setMaxAccid(int maxAccid) {
	m_maxAccid = abs(maxAccid);
	m_base = 7 * (2 * m_maxAccid + 1) + 5;
	calculateDiatonicMapping();
	m_transpose = 0;
}