string Options::getCommandLine(void) {
	string output;
	for (int i=0; i<(int)m_argv.size(); i++) {
		// check for how " and ' are dealt with in m_arguments...
		output += m_argv[i];
		if ((int)output.size() < (int)m_argv.size() - 1) {
			output += ' ';
		}
	}
	return output;
}