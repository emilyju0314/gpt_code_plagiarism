rect tile_to_rect(Tile tile) {
	rect r;
	r.x1 = tile.x;
	r.y1 = tile.y;
	r.x2 = tile.x + tile.w;
	r.y2 = tile.y + tile.h;
	return r;
}