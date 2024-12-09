static bool cmode_find_cmap(const cmode_map &cmap, std::string &cmode_str, uint32_t &cmode)
{
	// 1. try find by name
	for (auto &mode : cmap) {
		if (mode.second == cmode_str) {
			cmode = mode.first;
			return true;
		}
	}

	// 2. try convert integer
	//! @todo parse CMODE(dec)
	try {
		cmode = std::stoi(cmode_str, 0, 0);
		return true;
	}
	catch (std::invalid_argument &ex) {
		// failed
	}

	// Debugging output.
	std::ostringstream os;
	for (auto &mode : cmap)
		os << " " << mode.second;

	ROS_ERROR_STREAM_NAMED("uas", "MODE: Unknown mode: " << cmode_str);
	ROS_INFO_STREAM_NAMED("uas", "MODE: Known modes are:" << os.str());

	return false;
}