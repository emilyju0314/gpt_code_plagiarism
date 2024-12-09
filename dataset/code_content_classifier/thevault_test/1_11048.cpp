void DetLineFit::ComputeConstrainedDistances(const FCOORD &direction, double min_dist,
                                             double max_dist) {
  distances_.clear();
  square_length_ = direction.sqlength();
  // Compute the distance of each point from the line.
  for (auto &pt : pts_) {
    FCOORD pt_vector = pt.pt;
    // Compute |line_vector||pt_vector|sin(angle between)
    double dist = direction * pt_vector;
    if (min_dist <= dist && dist <= max_dist) {
      distances_.emplace_back(dist, pt.pt);
    }
  }
}