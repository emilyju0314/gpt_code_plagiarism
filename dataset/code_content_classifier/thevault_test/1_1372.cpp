Vector2 Heatmap::best_direction_for(Vector2 t_location, bool t_is_world_location) {
	Vector2 point = t_is_world_location ? m_grid->world_to_map(t_location) : t_location;
	Vector2 world_location = t_is_world_location ? t_location : m_grid->map_to_world(point);
	unsigned int cell_index = calculate_point_index(point);

	if (cell_index < 0 || cell_index >= m_cells_heat.size()) {
		return (m_last_player_cell_position - world_location).normalized();
	}

	Vector2 best_neighbor = point;
	int best_heat = m_cells_heat[cell_index];
	if (best_heat == -1) {
		return (m_last_player_cell_position - world_location).normalized();
	}

	for (int y = 0; y < 3; ++y) {
		for (int x = 0; x < 3; ++x) {
			Vector2 point_relative = Vector2(point.x + float(x) - 1.0f, point.y + float(y) - 1.0f);

			if (is_out_of_bounds(point_relative) || std::find(m_obstacles.begin(), m_obstacles.end(), point_relative) != m_obstacles.end()) {
				continue;
			}

			unsigned int point_relative_index = calculate_point_index(point_relative);
			if (point_relative_index == cell_index) {
				continue;
			}

			if (point_relative_index >= 0 && point_relative_index < m_cells_heat.size()) {
				int heat = m_cells_heat[point_relative_index];

				if (heat == -1) {
					continue;
				}

				if (heat <= best_heat) {
					best_heat = heat;
					best_neighbor = point_relative;
				}
			}
		}
	}

	Vector2 world_neighbor = m_grid->map_to_world(best_neighbor);
	Vector2 direction = (world_neighbor - world_location).normalized();
	if (direction.length_squared() == 0) {
		return (m_last_player_cell_position - world_location).normalized();
	}
	return direction;
}