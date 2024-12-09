void WERD::move(const ICOORD vec) {
  C_BLOB_IT cblob_it(&cblobs); // cblob iterator

  for (cblob_it.mark_cycle_pt(); !cblob_it.cycled_list(); cblob_it.forward()) {
    cblob_it.data()->move(vec);
  }
}