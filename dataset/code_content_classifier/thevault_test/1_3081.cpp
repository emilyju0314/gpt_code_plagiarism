void Map::_find_spawn(void) {
	//don't you just love for loops?
	for (int i = 0; i < lines.size(); i++) {
		for (int j = 0; j < lines.at(i).size(); j++) {

			for (int k = 0; k < tile_types.size(); k++) {
				if (tile_types.at(k).identifier == lines.at(i).at(j) &&
					tile_types.at(k).is_spawn) {
					Map::spawn_x = j * tile_w;
					Map::spawn_y = i * tile_h;
					return;
				}
			}

		}
	}
}