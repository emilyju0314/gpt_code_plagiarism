string Options::getDefinition(const string& optionName) {
	auto it = m_optionList.find(optionName);
	if (it == m_optionList.end()) {
		return "";
	} else {
		return m_optionRegister[it->second]->getDefinition();
	}
}