FCOORD FCOORD::nearest_pt_on_line(const FCOORD &line_point, const FCOORD &dir_vector) const {
  FCOORD point_vector(*this - line_point);
  // The dot product (%) is |dir_vector||point_vector|cos theta, so dividing by
  // the square of the length of dir_vector gives us the fraction of dir_vector
  // to add to line1 to get the appropriate point, so
  // result = line1 + lambda dir_vector.
  double lambda = point_vector % dir_vector / dir_vector.sqlength();
  return line_point + (dir_vector * lambda);
}