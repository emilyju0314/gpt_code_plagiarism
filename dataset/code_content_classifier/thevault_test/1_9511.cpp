char Options::getType(const string& optionName) {
	int index = getRegIndex(optionName);
	if (index < 0) {
		return -1;
	} else {
		return m_optionRegister[getRegIndex(optionName)]->getType();
	}
}