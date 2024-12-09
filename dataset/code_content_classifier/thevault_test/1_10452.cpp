SEAM *Wordrec::pick_good_seam(TBLOB *blob) {
  SeamPile seam_pile(chop_seam_pile_size);
  EDGEPT *points[MAX_NUM_POINTS];
  EDGEPT_CLIST new_points;
  SEAM *seam = nullptr;
  TESSLINE *outline;
  int16_t num_points = 0;

#ifndef GRAPHICS_DISABLED
  if (chop_debug > 2) {
    wordrec_display_splits.set_value(true);
  }

  draw_blob_edges(blob);
#endif

  PointHeap point_heap(MAX_NUM_POINTS);
  for (outline = blob->outlines; outline; outline = outline->next) {
    prioritize_points(outline, &point_heap);
  }

  while (!point_heap.empty() && num_points < MAX_NUM_POINTS) {
    points[num_points++] = point_heap.PeekTop().data();
    point_heap.Pop(nullptr);
  }

  /* Initialize queue */
  SeamQueue seam_queue(MAX_NUM_SEAMS);

  try_point_pairs(points, num_points, &seam_queue, &seam_pile, &seam, blob);
  try_vertical_splits(points, num_points, &new_points, &seam_queue, &seam_pile, &seam, blob);

  if (seam == nullptr) {
    choose_best_seam(&seam_queue, nullptr, BAD_PRIORITY, &seam, blob, &seam_pile);
  } else if (seam->priority() > chop_good_split) {
    choose_best_seam(&seam_queue, nullptr, seam->priority(), &seam, blob, &seam_pile);
  }

  EDGEPT_C_IT it(&new_points);
  for (it.mark_cycle_pt(); !it.cycled_list(); it.forward()) {
    EDGEPT *inserted_point = it.data();
    if (seam == nullptr || !seam->UsesPoint(inserted_point)) {
      for (outline = blob->outlines; outline; outline = outline->next) {
        if (outline->loop == inserted_point) {
          outline->loop = outline->loop->next;
        }
      }
      remove_edgept(inserted_point);
    }
  }

  if (seam) {
    if (seam->priority() > chop_ok_split) {
      delete seam;
      seam = nullptr;
    }
#ifndef GRAPHICS_DISABLED
    else if (wordrec_display_splits) {
      seam->Mark(edge_window);
      if (chop_debug > 2) {
        edge_window->Update();
        edge_window->Wait();
      }
    }
#endif
  }

  if (chop_debug) {
    wordrec_display_splits.set_value(false);
  }

  return (seam);
}