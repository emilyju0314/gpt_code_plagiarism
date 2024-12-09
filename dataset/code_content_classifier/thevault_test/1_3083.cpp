TileType Map::get_tile_type_at(float x, float y, float offset_x, float offset_y) {
	//round the x y coords given and divide them to grab the tile from the map array
	int x_con = int(((x + offset_x) / tile_w));
	int y_con = int(((y + offset_y) / tile_w));

	//if they are behind the map return air
	if (y < 0 || x < 0) {
		for (int i = 0; i < tile_types.size(); i++) {
			if (!tile_types.at(i).is_solid) {
				return tile_types.at(i);
			}
		}
	}
	//if they are outside of it return solid
	if (x_con > max_w || y_con > max_h - 1) {
		for (int i = 0; i < tile_types.size(); i++) {
			if (tile_types.at(i).is_solid) {
				return tile_types.at(i);
			}
		}
	}

	for (int i = 0; i < tile_types.size(); i++) {
		if (tile_types.at(i).identifier == lines.at(y_con).at(x_con)) {
			return tile_types.at(i);
		}
	}

	return TileType();
}