string Options::getArg(int index) {
	if (index == 0) {
		if (m_argv.empty()) {
			return "";
		} else {
			return m_argv[0];
		}
	}
	if (index < 1 || index > (int)m_arguments.size()) {
		m_error << "Error: argument " << index << " does not exist." << endl;
		return "";
	}
	return m_arguments[index - 1];
}