int32_t OL_BUCKETS::outline_complexity(C_OUTLINE *outline, // parent outline
                                       int32_t max_count,  // max output
                                       int16_t depth       // recurion depth
) {
  TDimension xmin, xmax;    // coord limits
  TDimension ymin, ymax;
  C_OUTLINE *child;         // current child
  int32_t child_count;      // no of children
  int32_t grandchild_count; // no of grandchildren
  C_OUTLINE_IT child_it;    // search iterator

  TBOX olbox = outline->bounding_box();
  xmin = (olbox.left() - bl.x()) / BUCKETSIZE;
  xmax = (olbox.right() - bl.x()) / BUCKETSIZE;
  ymin = (olbox.bottom() - bl.y()) / BUCKETSIZE;
  ymax = (olbox.top() - bl.y()) / BUCKETSIZE;
  child_count = 0;
  grandchild_count = 0;
  if (++depth > edges_max_children_layers) { // nested loops are too deep
    return max_count + depth;
  }

  for (auto yindex = ymin; yindex <= ymax; yindex++) {
    for (auto xindex = xmin; xindex <= xmax; xindex++) {
      child_it.set_to_list(&buckets[yindex * bxdim + xindex]);
      if (child_it.empty()) {
        continue;
      }
      for (child_it.mark_cycle_pt(); !child_it.cycled_list();
           child_it.forward()) {
        child = child_it.data();
        if (child == outline || !(*child < *outline)) {
          continue;
        }
        child_count++;

        if (child_count > edges_max_children_per_outline) { // too fragmented
          if (edges_debug) {
            tprintf(
                "Discard outline on child_count=%d > "
                "max_children_per_outline=%d\n",
                child_count,
                static_cast<int32_t>(edges_max_children_per_outline));
          }
          return max_count + child_count;
        }

        // Compute the "complexity" of each child recursively
        int32_t remaining_count = max_count - child_count - grandchild_count;
        if (remaining_count > 0) {
          grandchild_count += edges_children_per_grandchild *
                              outline_complexity(child, remaining_count, depth);
        }
        if (child_count + grandchild_count > max_count) { // too complex
          if (edges_debug) {
            tprintf(
                "Disgard outline on child_count=%d + grandchild_count=%d "
                "> max_count=%d\n",
                child_count, grandchild_count, max_count);
          }
          return child_count + grandchild_count;
        }
      }
    }
  }
  return child_count + grandchild_count;
}