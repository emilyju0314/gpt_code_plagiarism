Map::Map(char* file_path, float tile_w, float tile_h) {
	Map::map_file_path = file_path;

	Map::tile_w = tile_w;
	Map::tile_h = tile_h;

	Map::map_file.open(file_path);
	if (!map_file.is_open()) {
		throw std::runtime_error("Inavlid path to map file");
	}
}