void Heatmap::thread_done(Vector2 t_cell_position) {
	m_updating = false;

	m_max_heat = m_max_heat_cache;
	for (size_t i = 0; i < m_cells_heat.size(); ++i) {
		m_cells_heat[i] = m_cells_heat_cache[i];
	}
	m_last_player_cell_position = t_cell_position;

	update();
}