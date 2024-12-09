std::pair<size_t,size_t> bfs(ligra::graph const &g, vertex start) {
  auto BFS = BFS_F(g.num_vertices());
  BFS.Parents[start] = start;
  ligra::vertex_subset frontier(start); //creates initial frontier
  size_t levels = 0, visited = 0;
  while(!frontier.is_empty()) { //loop until frontier is empty
    visited += frontier.size();
    levels++;
    frontier = ligra::edge_map(g, frontier, BFS);
  }
  return std::make_pair(levels, visited);
}