void Wordrec::try_vertical_splits(EDGEPT *points[MAX_NUM_POINTS], int16_t num_points,
                                  EDGEPT_CLIST *new_points, SeamQueue *seam_queue,
                                  SeamPile *seam_pile, SEAM **seam, TBLOB *blob) {
  EDGEPT *vertical_point = nullptr;
  int16_t x;
  PRIORITY priority;
  TESSLINE *outline;

  for (x = 0; x < num_points; x++) {
    vertical_point = nullptr;
    for (outline = blob->outlines; outline; outline = outline->next) {
      vertical_projection_point(points[x], outline->loop, &vertical_point, new_points);
    }

    if (vertical_point && points[x] != vertical_point->next && vertical_point != points[x]->next &&
        points[x]->WeightedDistance(*vertical_point, chop_x_y_weight) < chop_split_length) {
      SPLIT split(points[x], vertical_point);
      priority = partial_split_priority(&split);
      choose_best_seam(seam_queue, &split, priority, seam, blob, seam_pile);
    }
  }
}