Tile Map::get_tile_at(float x, float y, float offset_x, float offset_y) {
	//round the x y coords given 
	int x_con = (int(((x + offset_x) / tile_w)) * tile_w);
	int y_con = (int(((y + offset_y) / tile_h)) * tile_h);
	//get the tile type at the given location
	TileType type = get_tile_type_at(x, y, offset_x, offset_y);

	if (type.identifier != NULL) {
		return Tile(type, x_con, y_con, tile_w, tile_h);
	} else {
		return Tile(TileType(), x_con, y_con, tile_w, tile_h);
	}
}