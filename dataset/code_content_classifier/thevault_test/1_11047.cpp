void DetLineFit::ComputeDistances(const ICOORD &start, const ICOORD &end) {
  distances_.clear();
  ICOORD line_vector = end;
  line_vector -= start;
  square_length_ = line_vector.sqlength();
  int line_length = IntCastRounded(sqrt(square_length_));
  // Compute the distance of each point from the line.
  int prev_abs_dist = 0;
  int prev_dot = 0;
  for (unsigned i = 0; i < pts_.size(); ++i) {
    ICOORD pt_vector = pts_[i].pt;
    pt_vector -= start;
    int dot = line_vector % pt_vector;
    // Compute |line_vector||pt_vector|sin(angle between)
    int dist = line_vector * pt_vector;
    int abs_dist = dist < 0 ? -dist : dist;
    if (abs_dist > prev_abs_dist && i > 0) {
      // Ignore this point if it overlaps the previous one.
      int separation = abs(dot - prev_dot);
      if (separation < line_length * pts_[i].halfwidth ||
          separation < line_length * pts_[i - 1].halfwidth) {
        continue;
      }
    }
    distances_.emplace_back(dist, pts_[i].pt);
    prev_abs_dist = abs_dist;
    prev_dot = dot;
  }
}