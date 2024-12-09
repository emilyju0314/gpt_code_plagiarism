void Map::render_map(float offset_x, float offset_y) {

	if (!_map_parsed) {
		throw std::runtime_error("Map has not been parsed! call parse_map to parse.");
	}
	
	al_hold_bitmap_drawing(true);

	for (int i = 0; i < max_h; i++) {
		for (int j = 0; j < max_w; j++) {
			char tile;
			if (lines.at(i).length() < max_w) {
				tile = '0';
			} else {
				tile = lines.at(i).at(j);
			}
			TileType temp;

			for (int k = 0; k < tile_types.size(); k++) {
				if (tile_types.at(k).identifier == tile) {
					temp = tile_types.at(k);
				}
			}

			if (temp.identifier == NULL) {
				temp = TileType('?', false);
				temp.color = al_map_rgb(220, 66, 244);
			}

			if (temp.has_image) {
				al_draw_bitmap(temp.image, (j * tile_w) + offset_x, (i * tile_h) + offset_y, 0);
			} else {
				if (temp.draw_wireframe) {
					al_draw_rectangle(
						(j * tile_w) + offset_x,
						(i * tile_h) + offset_y,
						((j * tile_w) + tile_w) + offset_x,
						((i * tile_h) + tile_h) + offset_y, temp.color, 3.0);
				} else {
					al_draw_filled_rectangle(
						(j * tile_w) + offset_x,
						(i * tile_h) + offset_y,
						((j * tile_w) + tile_w) + offset_x,
						((i * tile_h) + tile_h) + offset_y, temp.color);
				}
			}
		}
	}

	al_hold_bitmap_drawing(false);
}