string Options::getString(const string& optionName) {
	int index = getRegIndex(optionName);
	if (index < 0) {
		return "UNKNOWN OPTION";
	} else {
		return m_optionRegister[index]->getOption();
	}
}