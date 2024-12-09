void shrink_neighbor_list(
  DistanceComputer& qdis,
  std::priority_queue<NodeDistCloser>& resultSet1,
  size_t max_size)
{
  if (resultSet1.size() < max_size) {
      return;
  }
  std::priority_queue<NodeDistFarther> resultSet;
  std::vector<NodeDistFarther> returnlist;

  while (resultSet1.size() > 0) {
      resultSet.emplace(resultSet1.top().d, resultSet1.top().id);
      resultSet1.pop();
  }

  faiss::HNSW::shrink_neighbor_list(qdis, resultSet, returnlist, max_size);

  for (NodeDistFarther curen2 : returnlist) {
      resultSet1.emplace(curen2.d, curen2.id);
  }
}