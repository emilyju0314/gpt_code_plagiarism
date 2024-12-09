void OL_BUCKETS::extract_children( // recursive count
    C_OUTLINE *outline,            // parent outline
    C_OUTLINE_IT *it               // destination iterator
) {
  TDimension xmin, xmax; // coord limits
  TDimension ymin, ymax;
  TBOX olbox;
  C_OUTLINE_IT child_it; // search iterator

  olbox = outline->bounding_box();
  xmin = (olbox.left() - bl.x()) / BUCKETSIZE;
  xmax = (olbox.right() - bl.x()) / BUCKETSIZE;
  ymin = (olbox.bottom() - bl.y()) / BUCKETSIZE;
  ymax = (olbox.top() - bl.y()) / BUCKETSIZE;
  for (auto yindex = ymin; yindex <= ymax; yindex++) {
    for (auto xindex = xmin; xindex <= xmax; xindex++) {
      child_it.set_to_list(&buckets[yindex * bxdim + xindex]);
      for (child_it.mark_cycle_pt(); !child_it.cycled_list();
           child_it.forward()) {
        if (*child_it.data() < *outline) {
          it->add_after_then_move(child_it.extract());
        }
      }
    }
  }
}