void Map::_find_max(void) {
	std::string line;
	int max_x = 0;
	while (std::getline(map_file, line)) {
		lines.push_back(line);
		if (line.length() > max_x) {
			max_x = line.length();
		}
	}
	Map::max_w = max_x;
	Map::max_h = lines.size();
}