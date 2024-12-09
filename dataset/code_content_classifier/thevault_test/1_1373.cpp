void Heatmap::find_all_obstacles() {
	Ref<TileSet> tileset = m_grid->get_tileset();

	//TODO: Account for non-autotile tilesets.
	for (int y = m_y_min; y < m_y_max; ++y) {
		for (int x = m_x_min; x < m_x_max; ++x) {
			int cell_id = m_grid->get_cell(x, y);
			if (cell_id == -1 || !tileset->has_tile(cell_id)) {
				continue;
			}
			int cell_bitmask = tileset->autotile_get_bitmask(cell_id, m_grid->get_cell_autotile_coord(x, y));
			TileSet::BitmaskMode mode = tileset->autotile_get_bitmask_mode(cell_id);

			int all_covered = 325; //Bitmask is the sum of TileSet::BitmaskMode enum flags.
			if (mode == TileSet::BITMASK_3X3 || mode == TileSet::BITMASK_3X3_MINIMAL) {
				all_covered = 495;
			}

			if (cell_bitmask == all_covered) {
				m_obstacles.push_back(Vector2(x, y));
			}
		}
	}
}