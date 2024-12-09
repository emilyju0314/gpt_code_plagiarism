double DetLineFit::ConstrainedFit(const FCOORD &direction, double min_dist, double max_dist,
                                  bool debug, ICOORD *line_pt) {
  ComputeConstrainedDistances(direction, min_dist, max_dist);
  // Do something sensible with no points or computed distances.
  if (pts_.empty() || distances_.empty()) {
    line_pt->set_x(0);
    line_pt->set_y(0);
    return 0.0;
  }
  auto median_index = distances_.size() / 2;
  std::nth_element(distances_.begin(), distances_.begin() + median_index, distances_.end());
  *line_pt = distances_[median_index].data();
  if (debug) {
    tprintf("Constrained fit to dir %g, %g = %d, %d :%zu distances:\n", direction.x(), direction.y(),
            line_pt->x(), line_pt->y(), distances_.size());
    for (unsigned i = 0; i < distances_.size(); ++i) {
      tprintf("%d: %d, %d -> %g\n", i, distances_[i].data().x(), distances_[i].data().y(),
              distances_[i].key());
    }
    tprintf("Result = %zu\n", median_index);
  }
  // Center distances on the fitted point.
  double dist_origin = direction * *line_pt;
  for (auto &distance : distances_) {
    distance.key() -= dist_origin;
  }
  return sqrt(EvaluateLineFit());
}