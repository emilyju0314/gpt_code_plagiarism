std::vector<std::pair<flexible_type, flexible_type>> triple_apply_degree_count(
  sgraph& g, sgraph::edge_direction dir, bool use_batch_triple_apply_mock) {

  sgraph_compute::triple_apply_fn_type fn;
  g.init_vertex_field("__degree__", flex_int(0));
  std::vector<std::string> vertex_fields = g.get_vertex_fields();
  size_t degree_idx;
  for (size_t i = 0; i < vertex_fields.size(); ++i) {
    if (vertex_fields[i] == "__degree__") degree_idx = i;
  }

  if (dir == sgraph::edge_direction::IN_EDGE) {
    fn = [=](sgraph_compute::edge_scope& scope) {
      scope.lock_vertices();
      scope.target()[degree_idx]++;
      scope.unlock_vertices();
    };
  } else if (dir == sgraph::edge_direction::OUT_EDGE) {
    fn = [=](sgraph_compute::edge_scope& scope) {
      scope.lock_vertices();
      scope.source()[degree_idx]++;
      scope.unlock_vertices();
    };
  } else {
    fn = [=](sgraph_compute::edge_scope& scope) {
      scope.lock_vertices();
      scope.source()[degree_idx]++;
      scope.target()[degree_idx]++;
      scope.unlock_vertices();
    };
  }

  if (use_batch_triple_apply_mock) {
    sgraph_compute::batch_triple_apply_mock(g, fn, {"__degree__"});
  } else {
    sgraph_compute::triple_apply(g, fn, {"__degree__"});
  }

  auto result = g.fetch_vertex_data_field("__degree__");
  auto vertex_ids = g.fetch_vertex_data_field(sgraph::VID_COLUMN_NAME);
  std::vector<std::pair<flexible_type, flexible_type>> ret;
  for (size_t i = 0; i < result.size(); ++i) {
    std::vector<flexible_type> degree_vec;
    std::vector<flexible_type> id_vec;
    result[i]->get_reader()->read_rows(0, g.num_vertices(), degree_vec);
    vertex_ids[i]->get_reader()->read_rows(0, g.num_vertices(), id_vec);
    for (size_t j = 0; j < degree_vec.size(); ++j) {
      ret.push_back({id_vec[j], degree_vec[j]});
    }
  }
  g.remove_vertex_field("__degree__");
  return ret;
}