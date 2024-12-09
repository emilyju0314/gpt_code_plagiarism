int TBLOB::ComputeMoments(FCOORD *center, FCOORD *second_moments) const {
  // Compute 1st and 2nd moments of the original outline.
  LLSQ accumulator;
  TBOX box = bounding_box();
  // Iterate the outlines, accumulating edges relative the box.botleft().
  CollectEdges(box, nullptr, &accumulator, nullptr, nullptr);
  *center = accumulator.mean_point() + box.botleft();
  // The 2nd moments are just the standard deviation of the point positions.
  double x2nd = sqrt(accumulator.x_variance());
  double y2nd = sqrt(accumulator.y_variance());
  if (x2nd < 1.0) {
    x2nd = 1.0;
  }
  if (y2nd < 1.0) {
    y2nd = 1.0;
  }
  second_moments->set_x(x2nd);
  second_moments->set_y(y2nd);
  return accumulator.count();
}