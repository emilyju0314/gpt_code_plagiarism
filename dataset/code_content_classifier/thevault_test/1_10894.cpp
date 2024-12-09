void TBLOB::GetEdgeCoords(const TBOX &box, std::vector<std::vector<int>> &x_coords,
                          std::vector<std::vector<int>> &y_coords) const {
  x_coords.clear();
  x_coords.resize(box.height());
  y_coords.clear();
  y_coords.resize(box.width());
  CollectEdges(box, nullptr, nullptr, &x_coords, &y_coords);
  // Sort the output vectors.
  for (auto &coord : x_coords) {
    std::sort(coord.begin(), coord.end());
  }
  for (auto &coord : y_coords) {
    std::sort(coord.begin(), coord.end());
  }
}