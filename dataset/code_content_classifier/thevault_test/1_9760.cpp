void Tool_kernview::initialize(HumdrumFile& infile) {
	m_view_string = getString("view");
	m_hide_string = getString("hide");
	if (getBoolean("g")) {
		m_view_string = getKernString(infile, getString("g"));
	}
	if (getBoolean("G")) {
		m_hide_string = getKernString(infile, getString("G"));
	}
}