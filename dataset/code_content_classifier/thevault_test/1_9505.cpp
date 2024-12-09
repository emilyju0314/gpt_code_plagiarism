bool Options::getBoolean(const string& optionName) {
	int index = getRegIndex(optionName);
	if (index < 0) {
		return 0;
	}
	return m_optionRegister[index]->isModified();
}