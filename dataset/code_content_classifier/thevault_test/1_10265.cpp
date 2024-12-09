static bool is_blacklisted(std::string &pl_name, ros::V_string &blacklist, ros::V_string &whitelist)
{
	for (auto &bl_pattern : blacklist) {
		if (pattern_match(bl_pattern, pl_name)) {
			for (auto &wl_pattern : whitelist) {
				if (pattern_match(wl_pattern, pl_name))
					return false;
			}

			return true;
		}
	}

	return false;
}