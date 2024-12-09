void search_neighbors_to_add(
  GammaHNSW& hnsw,
  DistanceComputer& qdis,
  std::priority_queue<NodeDistCloser>& results,
  int entry_point,
  float d_entry_point,
  int level)
{
  std::set<int> visited_node;
  // top is nearest candidate
  std::priority_queue<NodeDistFarther> candidates;

  NodeDistFarther ev(d_entry_point, entry_point);
  candidates.push(ev);
  results.emplace(d_entry_point, entry_point);
  visited_node.insert(entry_point);

  while (!candidates.empty()) {
    // get nearest
    const NodeDistFarther &currEv = candidates.top();

    if (currEv.d > results.top().d) {
      break;
    }
    int currNode = currEv.id;
    candidates.pop();

    // loop over neighbors
    size_t begin, end;
    hnsw.neighbor_range(currNode, level, &begin, &end);
    for(size_t i = begin; i < end; i++) {
      storage_idx_t nodeId = hnsw.neighbors[i];
      if (nodeId < 0) break;
      if (visited_node.count(nodeId)) continue;
      visited_node.insert(nodeId);

      float dis = qdis(nodeId);
      NodeDistFarther evE1(dis, nodeId);

      if (results.size() < (size_t)hnsw.efConstruction ||
          results.top().d > dis) {

        results.emplace(dis, nodeId);
        candidates.emplace(dis, nodeId);
        if (results.size() > (size_t)hnsw.efConstruction) {
          results.pop();
        }
      }
    }
  }
}