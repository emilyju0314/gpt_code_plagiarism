void Wordrec::try_point_pairs(EDGEPT *points[MAX_NUM_POINTS], int16_t num_points,
                              SeamQueue *seam_queue, SeamPile *seam_pile, SEAM **seam,
                              TBLOB *blob) {
  int16_t x;
  int16_t y;
  PRIORITY priority;

  for (x = 0; x < num_points; x++) {
    for (y = x + 1; y < num_points; y++) {
      if (points[y] &&
          points[x]->WeightedDistance(*points[y], chop_x_y_weight) < chop_split_length &&
          points[x] != points[y]->next && points[y] != points[x]->next &&
          !is_exterior_point(points[x], points[y]) && !is_exterior_point(points[y], points[x])) {
        SPLIT split(points[x], points[y]);
        priority = partial_split_priority(&split);

        choose_best_seam(seam_queue, &split, priority, seam, blob, seam_pile);
      }
    }
  }
}