int Options::getRegIndex(const string& optionName) {
	if (m_suppressQ && (optionName == "options")) {
			return -1;
	}

	if (optionName == "options") {
		print(cout);
		return -1;
	}

	auto it = m_optionList.find(optionName);
	if (it == m_optionList.end()) {
		if (m_options_error_checkQ) {
			m_error << "Error: unknown option \"" << optionName << "\"." << endl;
			print(cout);
			return -1;
		} else {
			return -1;
		}
	} else {
		return it->second;
	}
}