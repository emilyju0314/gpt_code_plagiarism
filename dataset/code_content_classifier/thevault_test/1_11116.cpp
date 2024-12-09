BlobRegionType ColPartitionGrid::SmoothInOneDirection(
    BlobNeighbourDir direction, Image nontext_map, const TBOX &im_box,
    const FCOORD &rerotation, bool debug, const ColPartition &part,
    int *best_distance) {
  // Set up a rectangle search bounded by the part.
  const TBOX &part_box = part.bounding_box();
  TBOX search_box;
  ICOORD dist_scaling;
  ComputeSearchBoxAndScaling(direction, part_box, gridsize(), &search_box,
                             &dist_scaling);
  bool image_region = ImageFind::CountPixelsInRotatedBox(
                          search_box, im_box, rerotation, nontext_map) > 0;
  std::vector<int> dists[NPT_COUNT];
  AccumulatePartDistances(part, dist_scaling, search_box, nontext_map, im_box,
                          rerotation, debug, dists);
  // By iteratively including the next smallest distance across the vectors,
  // (as in a merge sort) we can use the vector indices as counts of each type
  // and find the nearest set of objects that give us a definite decision.
  unsigned counts[NPT_COUNT];
  memset(counts, 0, sizeof(counts));
  // If there is image in the search box, tip the balance in image's favor.
  int image_bias = image_region ? kSmoothDecisionMargin / 2 : 0;
  BlobRegionType text_dir = part.blob_type();
  BlobTextFlowType flow_type = part.flow();
  int min_dist = 0;
  do {
    // Find the minimum new entry across the vectors
    min_dist = INT32_MAX;
    for (int i = 0; i < NPT_COUNT; ++i) {
      if (counts[i] < dists[i].size() && dists[i][counts[i]] < min_dist) {
        min_dist = dists[i][counts[i]];
      }
    }
    // Step all the indices/counts forward to include min_dist.
    for (int i = 0; i < NPT_COUNT; ++i) {
      while (counts[i] < dists[i].size() && dists[i][counts[i]] <= min_dist) {
        ++counts[i];
      }
    }
    *best_distance = min_dist;
    if (debug) {
      tprintf("Totals: htext=%u+%u, vtext=%u+%u, image=%u+%u, at dist=%d\n",
              counts[NPT_HTEXT], counts[NPT_WEAK_HTEXT], counts[NPT_VTEXT],
              counts[NPT_WEAK_VTEXT], counts[NPT_IMAGE], image_bias, min_dist);
    }
    // See if we have a decision yet.
    auto image_count = counts[NPT_IMAGE];
    auto htext_score = counts[NPT_HTEXT] + counts[NPT_WEAK_HTEXT] -
                       (image_count + counts[NPT_WEAK_VTEXT]);
    auto vtext_score = counts[NPT_VTEXT] + counts[NPT_WEAK_VTEXT] -
                       (image_count + counts[NPT_WEAK_HTEXT]);
    if (image_count > 0 && image_bias - htext_score >= kSmoothDecisionMargin &&
        image_bias - vtext_score >= kSmoothDecisionMargin) {
      *best_distance = dists[NPT_IMAGE][0];
      if (!dists[NPT_WEAK_VTEXT].empty() &&
          *best_distance > dists[NPT_WEAK_VTEXT][0]) {
        *best_distance = dists[NPT_WEAK_VTEXT][0];
      }
      if (!dists[NPT_WEAK_HTEXT].empty() &&
          *best_distance > dists[NPT_WEAK_HTEXT][0]) {
        *best_distance = dists[NPT_WEAK_HTEXT][0];
      }
      return BRT_POLYIMAGE;
    }
    if ((text_dir != BRT_VERT_TEXT || flow_type != BTFT_CHAIN) &&
        counts[NPT_HTEXT] > 0 && htext_score >= kSmoothDecisionMargin) {
      *best_distance = dists[NPT_HTEXT][0];
      return BRT_TEXT;
    } else if ((text_dir != BRT_TEXT || flow_type != BTFT_CHAIN) &&
               counts[NPT_VTEXT] > 0 && vtext_score >= kSmoothDecisionMargin) {
      *best_distance = dists[NPT_VTEXT][0];
      return BRT_VERT_TEXT;
    }
  } while (min_dist < INT32_MAX);
  return BRT_UNKNOWN;
}