PRIORITY Wordrec::grade_sharpness(SPLIT *split) {
  PRIORITY grade;

  grade = point_priority(split->point1) + point_priority(split->point2);

  if (grade < -360.0) {
    grade = 0;
  } else {
    grade += 360.0;
  }

  grade *= chop_sharpness_knob; /* Values 0 to -360 */

  return (grade);
}