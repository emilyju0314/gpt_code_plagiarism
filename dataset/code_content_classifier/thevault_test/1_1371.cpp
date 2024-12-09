void Heatmap::_draw() {
	if (!m_draw_debug) {
		return;
	}

	Rect2 tile;
	Vector2 cell_size = m_grid->get_cell_size();
	tile.set_size(cell_size);
	cell_size /= 2;

	for (int y = int(m_y_min); y < int(m_y_max); ++y) {
		for (int x = int(m_x_min); x < int(m_x_max); ++x) {
			Vector2 point = Vector2(float(x), float(y));
			Vector2 world_position = m_grid->map_to_world(point);
			tile.set_position(world_position);

			unsigned int cell_index = calculate_point_index(point);
			int heat = m_cells_heat[cell_index];
			if (heat == -1) {
				continue;
			}
			float proportion = lerp(0.0f, 1.0f, float(heat) / float(m_max_heat));

			draw_rect(tile, Color(1.0f - proportion, 0, proportion, 0.75f), true);

			world_position += cell_size;
			Vector2 direction = best_direction_for(point, false);
			draw_rect(Rect2(world_position.x - 5, world_position.y - 5, 10, 10), Color(0, 1, 0), false);
			draw_line(world_position, world_position + (direction * 20), Color(1, 1, 1));
		}
	}
}