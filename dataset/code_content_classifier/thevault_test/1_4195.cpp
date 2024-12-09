bool cte::is_compatible(std::map<size_t, size_t>& config,
		std::vector<int>& evidence) {
	bool ok = true;
	for (std::map<size_t, size_t>::iterator mi = config.begin();
			mi != config.end(); ++mi) {
		size_t var = mi->first;
		size_t val = mi->second;
		if (evidence[var] < 0) {
			continue; // skip non-evidence variable
		} else {
			if (val != evidence[var]) {
				ok = false;
				break;
			}
		}
	}

	return ok;
}