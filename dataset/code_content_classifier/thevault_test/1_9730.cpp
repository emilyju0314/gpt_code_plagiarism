void Tool_semitones::initialize(void) {
	// processing of options goes here

	m_cdataQ      = getBoolean("cdata");
	m_count       = getBoolean("count");
	m_downQ       = getBoolean("down");
	m_firstQ      = getBoolean("first");
	m_leapQ       = getBoolean("leap");
	m_midiQ       = getBoolean("midi");
	m_noanalysisQ = getBoolean("no-analysis");
	m_noinputQ    = getBoolean("no-input");
	m_nomarkQ     = getBoolean("no-marks");
	m_notiesQ     = getBoolean("no-ties");
	m_pcQ         = getBoolean("pc");
	m_repeatQ     = getBoolean("repeat");
	m_norestsQ    = getBoolean("no-rests");
	m_secondQ     = getBoolean("second");
	m_stepQ       = getBoolean("step");
	m_upQ         = getBoolean("up");

	m_leap        = getInteger("jump");

	m_color       = getString("color");
	m_exclude     = getString("exclude");
	m_include     = getString("include");
	m_marker      = getString("mark");

	if (!m_firstQ && !m_secondQ) {
		m_firstQ  = true;
		m_secondQ = true;
	}
}