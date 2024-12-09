int Options::isDefined(const string& name) {
	if (m_optionList.find(name) == m_optionList.end()) {
		return 0;
	} else {
		return 1;
	}
}