void Options::appendOptions(int argc, char** argv) {
	m_processedQ = 0;
	for (int i=0; i<argc; i++) {
		m_argv.push_back(argv[i]);
	}
}