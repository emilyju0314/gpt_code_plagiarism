PRIORITY Wordrec::grade_split_length(SPLIT *split) {
  PRIORITY grade;
  float split_length;

  split_length = split->point1->WeightedDistance(*split->point2, chop_x_y_weight);

  if (split_length <= 0) {
    grade = 0;
  } else {
    grade = std::sqrt(split_length) * chop_split_dist_knob;
  }

  return (std::max(0.0f, grade));
}