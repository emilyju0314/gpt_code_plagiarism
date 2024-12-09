bool HumdrumFileSet::swap(int index1, int index2) {
	if (index1 < 0) { return false; }
	if (index2 < 0) { return false; }
	if (index1 >= (int)m_data.size()) { return false; }
	if (index2 >= (int)m_data.size()) { return false; }

	HumdrumFile* temp = m_data[index1];
	m_data[index1] = m_data[index2];
	m_data[index2] = temp;

	return true;
}